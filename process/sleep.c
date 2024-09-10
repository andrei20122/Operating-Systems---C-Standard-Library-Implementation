#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
   struct timespec time;
   time.tv_sec = seconds;
   time.tv_nsec = 0;

    struct timespec time2;

    int a = nanosleep(&time,&time2);

    if(a == -1){
        return time2.tv_sec;
    }

    return 0;
}