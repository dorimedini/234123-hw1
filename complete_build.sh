#!/bin/bash

cd /usr/src/linux-2.4.18-14custom
make bzImage
make modules
make modules_install
cd arch/i386/boot
cp -f bzImage /boot/vmlinuz-2.4.18-14custom
cd /boot
mkinitrd -f 2.4.18-14custom.img 2.4.18-14custom