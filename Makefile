obj-m +=hello.o

KDIR=/usr/src/linux-headers-4.15.0-50-generic

all:
	$(MAKE) -C $(KDIR) SUBDIR=$(PWD) modules
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order
