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

struct kernel_param_ops param_array_ops;
struct kernel_param_ops param_ops_charp;
struct kernel_param_ops param_ops_long;
struct kernel_param_ops param_ops_int;
struct kernel_param_ops param_ops_short;
struct kernel_param_ops aram_ops_int;

/**
 *  Strictly speaking, not a kernel stub, but we'll use it a lot
 */

int test_printf (const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    return vsnprintf(log_buffer, NBUF, fmt, args);
}
