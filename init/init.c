#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>

#include <errno.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    errno = 0;

    time_t t;
    while (1)
    {
        if (syscall(335, &t) != -1)
            printf("%ld\n", t);
        else
            printf("error: errno set to %d\n", errno);
        sleep(1);
    }

    return 0;
}
