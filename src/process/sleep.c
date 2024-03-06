#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
    int ret = syscall(__NR_nanosleep, rqtp, rmtp);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 1;
}

unsigned int sleep(unsigned int seconds)
{
    struct timespec t1, t2;

    t1.tv_nsec = 0;
    t1.tv_sec = seconds;

    t2.tv_nsec = 0;
    t2.tv_sec = 0;

    unsigned int ret = nanosleep(&t1, &t2);

    return ret;
}

