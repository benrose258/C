# obj-m specified we're a kernel module.
obj-m += hello.o

# Set the path to the Kernel build utils.
#KBUILD=/lib/modules/$(shell uname -r)/build/

# Manual override for setting the path to the Kernel build utils
KBUILD=/lib/modules/$(shell uname -r)/build/

#all:
#	$(MAKE) clean && $(MAKE) all

default:
	$(MAKE) -C $(KBUILD) M=$(PWD) modules

clean:
	$(MAKE) -C $(KBUILD) M=$(PWD) clean

menuconfig:
	$(MAKE) -C $(KBUILD) M=$(PWD) menuconfig
