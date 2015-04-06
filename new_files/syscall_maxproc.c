/**
 * Put this in:
 * /usr/src/linux-2.4.18-14custom/arch/i386/kernel/
 */


//#include "syscall_maxproc.h"
//#include "../../../include/linux/sched.h"
#include "linux/sched.h"
//#include <sched.h> Doesn't find this



/**
 * System calls
 */
int sys_set_child_max_proc(int limit) {
	
	if (current->max_proc_from_above <= limit &&	// Make sure the child isn't trying to
		current->max_proc_from_above >= 0) {		// override the parent limit.
		return -1;
	}
	
	current->max_proc_for_children = limit;			// Set the limit
	return 0;
	
}


int sys_get_max_proc() {
	return current->max_proc_from_above;
}


int sys_get_subproc_count() {
	return current->subtree_size;
}


