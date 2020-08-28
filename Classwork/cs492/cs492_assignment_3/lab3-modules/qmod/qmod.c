#include <linux/device.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

// Define the module metadata.
#define MODULE_NAME "qmod"
#define DEVICE_NAME "qmod"
#define CLASS_NAME  "qmod"

MODULE_AUTHOR("Ben Rose");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A module which provides a shared queue");
MODULE_VERSION("1.0");

// Define the name parameter.
static char *name = "brose1";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

// The device number, automatically set. The message buffer and current message
// size. The number of device opens and the device class struct pointers.
static int majorNumber;
static struct class*  qmodClass  = NULL;
static struct device* qmodDevice = NULL;

// Declare the shared queue data structure (a static data structure in the KM).
#define BUFFER_LENGTH 256

struct qnode {
  char message[BUFFER_LENGTH];
  int mesglen;
  struct qnode *next;
};

struct qheader {
  struct qnode *front;
  struct qnode *last;
};

static struct qheader *queue; // Declaring an instance of the queue named "queue"

// Declare a mutex for ensuring mutual exclusion on the read and write operations.
static DEFINE_MUTEX(lock);

// Prototypes for our device functions.
static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

// Create the file operations instance for our driver.
static struct file_operations fops =
{
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};

static int __init mod_init(void)
{
    pr_info("%s: module loaded at 0x%p\n", MODULE_NAME, mod_init);

  // Initialize the queue data structure
	queue = kmalloc(100000, __GFP_IO | __GFP_FS); // Allocate kernel memory for the queue
	queue->front = NULL; // Initialize the front node of the queue to be NULL, since the queue is empty
	queue->last = NULL; // Initialize the last node of the queue to be NULL, since the queue is empty
  // Create a mutex to guard io operations.
	mutex_init(&lock);

  // Register the device, allocating a major number.
  majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
  if (majorNumber < 0) {
      pr_alert("%s: failed to register a major number\n", MODULE_NAME);
      return majorNumber;
  }
  pr_info("%s: registered correctly with major number %d\n", MODULE_NAME, majorNumber);

  // Create the device class.
  qmodClass = class_create(THIS_MODULE, CLASS_NAME);
  if (IS_ERR(qmodClass)) {
      // Cleanup resources and fail.
      unregister_chrdev(majorNumber, DEVICE_NAME);
      pr_alert("%s: failed to register device class\n", MODULE_NAME);

      // Get the error code from the pointer.
      return PTR_ERR(qmodClass);
  }
  pr_info("%s: device class registered correctly\n", MODULE_NAME);

  // Create the device.
  qmodDevice = device_create(qmodClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
  if (IS_ERR(qmodDevice)) {
      class_destroy(qmodClass);
      unregister_chrdev(majorNumber, DEVICE_NAME);
      pr_alert("%s: failed to create the device\n", DEVICE_NAME);
      return PTR_ERR(qmodDevice);
  }
  pr_info("%s: device class created correctly\n", DEVICE_NAME);

  // Success!
  return 0;
}

static void __exit mod_exit(void)
{
    pr_info("%s: unloading...\n", MODULE_NAME);
    device_destroy(qmodClass, MKDEV(majorNumber, 0));
    class_unregister(qmodClass);
    class_destroy(qmodClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);

  // Destroy the mutex and the queue
	mutex_destroy(&lock); // Destroy the mutex
	kfree(queue); // Destroy the queue by freeing the memory allocated to it in kernel space
    pr_info("%s: device unregistered\n", MODULE_NAME);
}

/** @brief The device open function that is called each time the device is opened
 *  @param inodep A pointer to an inode object (defined in linux/fs.h)
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 */
static int dev_open(struct inode *inodep, struct file *filep){
    pr_info("%s: device has been opened.\n", MODULE_NAME);
    return 0;
}

/** @brief This function is called whenever device is being read from user space i.e. data is
 *  being sent from the device to the user. In this case is uses the copy_to_user() function to
 *  send the buffer string to the user and captures any errors.
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 *  @param buffer The pointer to the buffer to which this function writes the data
 *  @param len The length of the b
 *  @param offset The offset if required
 */
static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
   char message[BUFFER_LENGTH] = { 0 };
   int messageSize;
   int error_count;

   // Use a mutex to avoid race conditions.
   mutex_lock(&lock); // Lock the mutex for work to be done
   if (queue->last == NULL) { // If the last node doesn't exist, the queue is empty
	mutex_unlock(&lock); // Unlock the mutex
	printk("I'm dev_read! I just unlocked the mutex early since the queue is empty! Also,\nERROR: You are using the remove operation on an empty queue. That doesn't work.");
	return -1; // Return -1 to indicate that the queue is empty
   } else if (queue->last->next == NULL) { // If the last node's next node is null, then the queue has one item in it, and the front node is equal to the last node.
	messageSize = queue->front->mesglen;
	queue->last = NULL; // Set the last node to NULL, since we removed the first (and only) item
	queue->front = NULL; // Set the front node to NULL, since we removed the first (and only) item
    } else { // The queue has at least three items in it.
	messageSize = queue->front->mesglen;
	struct qnode *temp = queue->last; // Set the temporary node to be the last node as we iterate over the queue for removal
	while (temp->next->next != NULL) { // While our temporary node is not the node before the head
		temp = temp->next; // Temp goes to the next node until it is two nodes before the front
	}
	queue->front = temp; // Set the head to be the node right before the front
	queue->front->next = NULL; // Set the variable after the new head to be null, as front->next must always be null, since it is at the front of the queue.
   }
   mutex_unlock(&lock); // Unlock the mutex when work is done
   error_count = copy_to_user(buffer, message, messageSize); // original error_count statement, restore if modification is not functional
   if (error_count==0) {
      pr_info("%s: sent %d characters to a client\n", MODULE_NAME, messageSize);
      return 0;
   } else {
      pr_err("%s: failed to send message to a client (error=%d)\n", MODULE_NAME, error_count);
      return -EFAULT;
   }
}

char *strcopy(char *dest, const char *source) { // My own implementation of strcpy adapted for this program
	int count = 0;
	char *src = source;
	while (src[count] != '\0') {
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return dest;
}

/** @brief This function is called whenever the device is being written to from user space i.e.
 *  data is sent to the device from the user. The data is copied to the message[] array in this
 *  LKM using the sprintf() function along with the length of the string.
 *  @param filep A pointer to a file object
 *  @param buffer The buffer to that contains the string to write to the device
 *  @param len The length of the array of data that is being passed in the const char buffer
 *  @param offset The offset if required
 */
static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    // Use a mutex to avoid race conditions.
    struct qnode *addme = kmalloc(1000, __GFP_IO | __GFP_FS); // Create the node to be added
    printk("Len = \"%d\", buffer = \"%s\"", len, buffer);
    strcpy(addme->message, buffer); // Make addme's message = buffer using strcopy
    addme->mesglen = len; // Make the length of the message be the length passed through
    printk("addme->message = \"%s\", addme->mesglen = \"%d\"", addme->message, addme->mesglen);
    int mutex_debug = mutex_lock_interruptible(&lock); // Doing testing to see if the mutex is causing problems
    if (queue->last == NULL) { // The queue is empty, add the first node to the queue as the first and last node
	addme->next = NULL; // Set the next value for the addme node to be NULL
	queue->last = addme; // Set the last node = addme
	queue->front = addme; // Set the front node = addme, since there is only one item in the queue now.
   } else if (queue->last->next == NULL) { // The queue has one node in it, and the front node is equal to the last node
	addme->next = queue->front; // The next node for addme is now the front node, since the queue is now two items long
	queue->last = addme; // The last element in the queue becomes addme
	queue->last->next = queue->front;
   } else { // The queue has two or more nodes in it
	printk("I'm dev_write! I'm in the else statement! The queue has two or more nodes in it!");

	addme->next = queue->last; // The next node for addme is the previous last node
	queue->last = addme; // Make addme the new last node
    }
    kfree(addme); // Free up the allocated memory for the addme node
    mutex_unlock(&lock); // Unlock the mutex when work is done
    int is_mutex_locked = mutex_is_locked(&lock);
    pr_info("%s: received %zu characters from the user\n", MODULE_NAME, len);
    return len;
}

/** @brief The device release function that is called whenever the device is closed/released by
 *  the userspace program
 *  @param inodep A pointer to an inode object (defined in linux/fs.h)
 *  @param filep A pointer to a file object (defined in linux/fs.h)
 */
static int dev_release(struct inode *inodep, struct file *filep) {
     pr_info("%s: device successfully closed\n", MODULE_NAME);
     return 0;
}

// Register the operations to be executed when the KM is loaded and unloaded
module_init(mod_init);
module_exit(mod_exit);
