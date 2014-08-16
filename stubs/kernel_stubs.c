/**
 *  LKMPG kernel stubs
 *  - inlcude kernel headers
 *  - must be compiled with kernel make
 *  - cannot use C++, StdCLib or CppUTest
 */

/// TODO: Make printk() append to buffer

#include <stdarg.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

/**
 *  Kernel function stubs
 */

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
