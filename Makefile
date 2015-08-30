
CC=arm-none-eabi-gcc
CFLAGS=-O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles
OBJCOPY=arm-none-eabi-objcopy

all: kernel.img

kernel.elf: main.c
	$(CC) $(CFLAGS) main.c -o kernel.elf

kernel.img: kernel.elf
	$(OBJCOPY) kernel.elf -O binary kernel.img

clean:
	rm kernel.elf
	rm kernel.img
