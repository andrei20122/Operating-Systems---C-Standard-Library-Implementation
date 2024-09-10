// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	
	long a = syscall(9,addr,length,prot,flags,fd,offset);
    
	if(a < 0){
		errno = -a;
		return (void*)-1;
	}
	return (void*)a;

	//return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long a = syscall(25,old_address,old_size,new_size,flags);
    
	if(a < 0){
		errno = -a;
		return (void*)-1;
	}
	return (void*)a;

	//return MAP_FAILED;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int a = syscall(11,addr,length);
    
	if(a < 0){
		errno = -a;
		return -1;
	}
	

	return a;
}
