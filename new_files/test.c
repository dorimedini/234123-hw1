#include <stdio.h>
#include <string.h>
#include "syscall_maxproc.h"

#include "c_test_utils.h"

/**
 * TEST: Correct return values
 *
 * - Successful child_max_proc setting should return 0
 * - If the parent is more limiting than the requested
 *   child_max_proc, returns -1 and sets errno=EINVAL
 * - If there is no limit, get_limit should return -1
 * - If too many processes are created, sets errno=EAGAIN
 */
void test_return_values() {
	set_child_max_proc(2);
	printf("%d",get_max_proc());
	get_subproc_count();
	SUCCESS();
}

/**
 * TEST: Process overflow
 *
 * Make sure the system correctly handles a process's
 * request to create child processes.
 *
 * - Allow a process with no limit to create lots
 * - Make sure a limited child is correctly limited
 * - A limits to 5, creates B, then limits to 10.
 *   Make sure B can only create 5 processes.
 * - A limits to 5, creates B, limits to 10, creates
 *   C. Make sure B stops at 5 and C at 10.
 * - Make sure the correct limit is applied:
 *   . Only the parent's most recent call to set_child_proc
 *     should count as a limit
 *   . A grandparent limit may be exceeded while the
 *     direct parent's limit is not - make sure the
 *     fork still fails
 * - Make sure that after illegal calls, the system
 *   behaves as it should:
 *   . After a process B tries to set it's child limit
 *     to something larger than it's parent A's limit,
 *     create a child process C and let C create
 *     processes. Make sure that when B's correct child
 *     limitation is reached, C cannot create more
 *     processes.
 * - Make sure the system correctly handles parent death, <---- STILL UNSURE IF THIS IS THE DESIRED BEHAVIOUR
 *   limit inheritance and orphanage. To do this:
 *   1.  Create a process A										____A____
 *   2.  Let A limit it's children to 15					   /		 \
 *   3.  Let A create process B								 _X_		 _B_
 *   4.  Let A limit it's children to 20					/ | \		/ | \
 *   5.  Let A create process X	(to spice things up)					 _C_
 *   6.  Let B limit it's children to 10								/ | \
 *   7.  Let B create process C										   /  |
 *   8.  Let C create process E										 _E   |
 *   9.  Let C limit it's children to 5								/ |  _D_
 *   10. Let C create process D											/ | \
 *   11. Make sure D can only create 5 processes
 *   12. Make sure E can create more (as per B's limit)
 *   12. Let C call exit()
 *   13. Make sure D can still only create 5 processes
 *   14. Let B wait() for C
 *   15. Make sure E can now create 15 processes but D
 *       may still only create 5
 */
void test_process_overflow() {
	
	SUCCESS();
}




/**
 * Main.
 *
 * Calls all tests.
 */
int main() {

	// Print title
	start();
	
	// Tests
	test_return_values();
	
	// Print end
	end();
	return 0;
}

