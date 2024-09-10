// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	
	//return -1;

	
	int a = syscall(8,fd,offset,whence);
	if(a < 0){
		errno = -a;
		return -1;
	}
	return a;
}
