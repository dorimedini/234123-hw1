#!/bin/bash

cd /usr/src/linux-2.4.18-14custom
make bzImage
cp -f bzImage /boot/vmlinuz-2.4.18-14custom