EXTRA_CFLAGS += -g -DUNIT_TEST -Werror -Wextra -Wno-unused-parameter -Wno-declaration-after-statement

obj-m += chardev.o
obj-m += chardev_wrapper.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
