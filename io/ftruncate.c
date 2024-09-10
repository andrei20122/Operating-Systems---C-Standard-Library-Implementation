// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	
	//return -1;

	
	int a = syscall(77,fd,length);
	if(a < 0){
		errno = -a;
		return -1;
	}
	return a;
}
