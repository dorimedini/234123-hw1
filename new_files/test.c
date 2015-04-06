#include <stdio.h>
#include <string.h>
#include "syscall_maxproc.h"

#include "c_test_utils.h"
/**
 * TEST: Correct return values
 *
 * - Successful child_max_proc setting should return 0
 * - If the parent is more limiting than the requested
 *   child_max_proc, returns -1
 * - If there is no limit, get_limit should return -1
 */


int main() {
	start();
	
	end();
	return 0;
}

