KDIR  := /work/platform/rk3399-nougat/kernel

# Kernel modules
obj-m += hello.o

# Specify flags for the module compilation.
#EXTRA_CFLAGS=-g -O0

build: kernel_modules

kernel_modules:
	make -C ${KDIR} M=$(PWD) modules

clean:
	make -C ${KDIR} M=$(PWD) clean
