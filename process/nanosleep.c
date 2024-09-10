#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int nanosleep(const struct timespec* req, struct timespec* rem) {
    int a = syscall(35, req, rem);
    
	if(a < 0){
		errno = -a;
		return -1;
	}
	return a;
}