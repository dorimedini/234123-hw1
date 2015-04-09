#!/bin/bash

cp -v /mnt/hgfs/HW/234123-hw1/new_files/test.c /root/tests/
cd /root/tests
dos2unix test.c
cp -v /mnt/hgfs/HW/234123-hw1/new_files/c_test_utils.h /root/tests/
cd /root/tests
dos2unix c_test_utils.h
cp -v /mnt/hgfs/HW/234123-hw1/new_files/syscall_maxproc.c /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
cd /usr/src/linux-2.4.18-14custom/arch/i386/kernel
dos2unix syscall_maxproc.c
cp -v /mnt/hgfs/HW/234123-hw1/new_files/syscall_maxproc.h /usr/include/
cd /usr/include
dos2unix syscall_maxproc.h
cp -v /mnt/hgfs/HW/234123-hw1/edited_kernel_files/entry.S /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
cd /usr/src/linux-2.4.18-14custom/arch/i386/kernel
dos2unix entry.S
cp -v /mnt/hgfs/HW/234123-hw1/edited_kernel_files/sched.h /usr/src/linux-2.4.18-14custom/include/linux/
cd /usr/src/linux-2.4.18-14custom/include/linux
dos2unix sched.h
cp -v /mnt/hgfs/HW/234123-hw1/edited_kernel_files/Makefile /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
cd /usr/src/linux-2.4.18-14custom/arch/i386/kernel
dos2unix Makefile
cp -v /mnt/hgfs/HW/234123-hw1/edited_kernel_files/fork.c /usr/src/linux-2.4.18-14custom/kernel/
cd /usr/src/linux-2.4.18-14custom/kernel
dos2unix fork.c
cp -v /mnt/hgfs/HW/234123-hw1/edited_kernel_files/exit.c /usr/src/linux-2.4.18-14custom/kernel/
cd /usr/src/linux-2.4.18-14custom/kernel
dos2unix exit.c
