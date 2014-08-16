/**
 *  LKMPG kernel stubs
 */

/// TODO: Make printk() append to buffer

#include <stdarg.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>

#define NBUF 5096L
static char log_buffer[NBUF];
static char log_level[3];


/**
 *  Kernel function stubs
 */
asmlinkage __printf(1, 2) __cold
int printk (const char * fmt, ...)
{
    va_list args;
    strncpy(log_level, fmt, 2);
    fmt += 2;
    va_start(args, fmt);
    return vsnprintf(log_buffer, NBUF, fmt, args);
}

int set_func(const char *val, const struct kernel_param *kp)
{
    (void) val;
    (void) kp;
    return 0;
}

int get_func(char *buffer, const struct kernel_param *kp)
{
    (void) buffer;
    (void) kp;
    return 0;
}

void free_func(void * m) { (void)m; }

struct kernel_param_ops param_array_ops = { .set = set_func, .get = get_func, .free = free_func };
struct kernel_param_ops param_ops_charp = { .set = set_func, .get = get_func, .free = free_func };
struct kernel_param_ops param_ops_long = { .set = set_func, .get = get_func, .free = free_func };
struct kernel_param_ops param_ops_int = { .set = set_func, .get = get_func, .free = free_func };
struct kernel_param_ops param_ops_short = { .set = set_func, .get = get_func, .free = free_func };
struct kernel_param_ops aram_ops_int = { .set = set_func, .get = get_func, .free = free_func };

/**
 *  Strictly speaking, not a kernel stub, but we'll use it a lot
 */

int test_printf (const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    return vsnprintf(log_buffer, NBUF, fmt, args);
}
