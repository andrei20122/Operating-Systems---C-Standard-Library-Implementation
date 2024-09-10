// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	
	//return -1;

	
	int a = syscall(76,path,length);
	if(a < 0){
		errno = -a;
		return -1;
	}
	return a;
}
