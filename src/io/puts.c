#include <unistd.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdio.h>
#include <string.h>

int puts(const char *str)
{
    if (str == NULL) {
        return -1;
    }

    int ret = write(1, str, strlen(str));
    if (ret < 0) {
        return -1;
    }

    char c = '\n';
    ret = write(1, &c, 1);
    if (ret < 0) {
        return -1;
    }

    return 1;
}

