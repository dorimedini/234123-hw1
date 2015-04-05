/**
 * Put this in:
 * /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
 */


#include "../../../include/linux/syscall_maxproc.h"
//#include "../../../include/linux/sched.h"
#include <sched.h>



/**
 * System calls
 */
int sys_set_child_max_proc(int limit) {
	return limit+1;
}


int sys_get_max_proc() {
	return 2;
}


int sys_get_subproc_count() {
	return 3;
}


