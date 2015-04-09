#!/bin/bash

cp -vu /mnt/hgfs/HW/234123-hw1/original_kernel_files/entry.S /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
cd /usr/src/linux-2.4.18-14custom/arch/i386/kernel
dos2unix entry.S
cp -vu /mnt/hgfs/HW/234123-hw1/original_kernel_files/sched.h /usr/src/linux-2.4.18-14custom/include/linux/
cd /usr/src/linux-2.4.18-14custom/include/linux
dos2unix sched.h
cp -vu /mnt/hgfs/HW/234123-hw1/original_kernel_files/Makefile /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
cd /usr/src/linux-2.4.18-14custom/arch/i386/kernel
dos2unix Makefile
cp -vu /mnt/hgfs/HW/234123-hw1/original_kernel_files/fork.c /usr/src/linux-2.4.18-14custom/kernel/
cd /usr/src/linux-2.4.18-14custom/kernel
dos2unix fork.c
cp -vu /mnt/hgfs/HW/234123-hw1/original_kernel_files/exit.c /usr/src/linux-2.4.18-14custom/kernel/
cd /usr/src/linux-2.4.18-14custom/kernel
dos2unix exit.c
