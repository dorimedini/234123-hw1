#include <stdio.h>
#include "syscall_maxproc.h"

int main() {
	int a = set_child_max_proc(5);
	int b = get_max_proc();
	int c = get_subproc_count();
	printf("set_max: %d\nget_max: %d\nget_subproc: %d\n",a,b,c);
	return 0;
}