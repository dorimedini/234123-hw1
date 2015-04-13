#!/bin/bash

# compile Asael's and Aviv's tests
cd /mnt/hgfs/HW/234123-hw1/other_peoples_tests/asael/test_wet1-1/
g++ /mnt/hgfs/HW/234123-hw1/other_peoples_tests/asael/test_wet1-1/test_runner.cpp -o /mnt/hgfs/HW/234123-hw1/other_peoples_tests/asael/test_wet1-1/test_runner

# run Aviv's script
/mnt/hgfs/HW/234123-hw1/other_peoples_tests/asael/test_wet1-1/run_tests.sh