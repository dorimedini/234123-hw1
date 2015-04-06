/**
 * Put this in:
 * /usr/include/
 */

#ifndef _SYSCALL_MAXPROC_H
#define _SYSCALL_MAXPROC_H

#include <errno.h>
//#include "/usr/include/errno.h"
extern int errno;

/**
 * Sets the maximum number of processes each child may create
 * in it's process tree.
 *
 * For example, if process A calls set_child_max_proc(5)
 * and then creates a child process B, B may create a
 * total of 5 processes. If B creates a child C, C may
 * create only 4 (de facto)... etc.
 * 
 * A process may not set its own max_child_proc value
 * to anything greater than its own limitation minus 1.
 *
 * Input: Max processes / negative number
 * Behaviour: 
 * - If it attempted to exceed its own limitation
 *   minus 1, return -1 and set errno to EPERM.
 * - If a negative value was sent, reset the value
 *   of max_child_proc to the process's own limitation.
 * - If the process already has children, it doesn't
 *   matter. The limitation will be reset.
 * - Returns 0 if successful
 */
int set_child_max_proc(int limit) {
	
	int ret = set_child_max_proc_wrapper(limit);
	
	if (ret == -1) {			// Attempted to override parent limit
		errno = EPERM;
	}
	
	return ret;
	
}

/**
 * Returns the current limit this process has on
 * creating child processes
 *
 * - If max_proc wasn't set yet, returns -1 and
 *   sets errno to EINVAL
 */
int get_max_proc() {
	return get_max_proc_wrapper();
}

/**
 * Returns the total number of processes in the
 * subtree of processes with the current process
 * as it's root (including itself).
 */
int get_subproc_count() {
	return get_subproc_count_wrapper();
}



/**
 * Wrapper functions (see user functions above
 * for documentation)
 */
int set_child_max_proc_wrapper(int limit) {
	long __res;
	__asm__ volatile (
		"movl $243, %%eax;"				// System call number
		"movl %1, %%ebx;"				// Send "limit" as a parameter
		"int $0x80;"					// System interrupt
		"movl %%eax,%0"					// Store the returned value
		: "=m" (__res)					// in __res
		: "m" ((long)limit)				// Input (%1 in the stack)
		: "%eax","%ebx"					// Registers used
	);
	if ((unsigned long)(__res) >= (unsigned long)(-125)) {
		errno = -(__res); __res = -1;	// Convert the output to have
	}									// correct +- sign?
	return (int)(__res);
}
int get_max_proc_wrapper() {
	long __res;
	__asm__ volatile (
		"movl $244, %%eax;"				// System call number
		"int $0x80;"					// System interrupt
		"movl %%eax,%0"					// Store the returned value
		: "=m" (__res)					// in __res
		: 								// No input
		: "%eax"						// Registers used
	);
	if ((unsigned long)(__res) >= (unsigned long)(-125)) {
		errno = -(__res); __res = -1;	// Convert the output to have
	}									// correct +- sign?
	return (int)(__res);
}
int get_subproc_count_wrapper() {
	long __res;
	__asm__ volatile (
		"movl $245, %%eax;"				// System call number
		"int $0x80;"					// System interrupt
		"movl %%eax,%0"					// Store the returned value
		: "=m" (__res)					// in __res
		: 								// No input
		: "%eax"						// Registers used
	);
	if ((unsigned long)(__res) >= (unsigned long)(-125)) {
		errno = -(__res); __res = -1;	// Convert the output to have
	}									// correct +- sign?
	return (int)(__res);
}


#endif