// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
	int a = syscall(5,fd,st);
	if(a < 0){
		errno = -a;
		return -1;
	}
	return a;

}
