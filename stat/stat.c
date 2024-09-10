// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int a = syscall(4,path,buf);
	if(a < 0){
		errno = -a;
		return -1;
	}
	return a;

}
