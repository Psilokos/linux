#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/time.h>

SYSCALL_DEFINE1(uptime, time_t * __user, t)
{
    struct timespec ts;
    get_monotonic_boottime(&ts);
    if (t && copy_to_user(t, &ts, sizeof(ts)))
        return -EFAULT;
    return ts.tv_sec;
}
