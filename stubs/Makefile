EXTRA_CFLAGS += -g -Werror -Wextra -Wno-unused-parameter -Wno-declaration-after-statement

obj-m += kernel.o
kernel-objs := getuser.o putuser.o kernel_stubs.o


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
