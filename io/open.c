// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list valist;
	long a, b,num;

	va_start(valist, num);
	a = va_arg(valist, long);

	int aux = syscall(2,filename,flags,a);
	if(aux < 0){
		errno = -aux;
		return -1;
	}
	return aux;
}
