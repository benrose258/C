#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

// Define the module metadata.
#define MODULE_NAME "hello"
MODULE_AUTHOR("Ben Rose");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple kernel module to greet the installer");
MODULE_VERSION("1.0");

// Define the name parameter.
static char *name = "brose1";
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

// Define the function to initialize the Hello module and say hello
static int __init hello_init(void) {
    pr_info("%s: module loaded at 0x%p\n", MODULE_NAME, hello_init); // Load the module into the kernel
    printk(KERN_INFO "Hello, %s, from the \"Hello\" kernel module!", name); // Say hello to the named user from the module
    return 0;
}

// Define the function to say goodbye and deinitialize the Hello module
static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, %s, from the \"Hello\" kernel module!", name); // Say goodbye to the named user from the module
    pr_info("%s: module unloaded from 0x%p\n", MODULE_NAME, hello_exit); // Unload the module from the kernel
}

// Register the operations to be executed when the Kernel Module is loaded and unloaded
module_init(hello_init); // Loading the module
module_exit(hello_exit); // Unloading the module
