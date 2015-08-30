
CC=arm-none-eabi-gcc
CFLAGS=-O2 -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles

kernel.elf: main.c
	$(CC) $(CFLAGS) main.c -o kernel.elf
