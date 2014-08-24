/**
 *  LKMPG kernel stubs
 *  - inlcude kernel headers
 *  - code would normally run in kernen space
 *  - must be compiled with kernel make
 *  - cannot use C++, StdCLib or CppUTest
 */

#include "kernel_stubs.h"

#include <linux/string.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <asm/uaccess.h>       /* for get_user */

extern int register_chrdev_result;

/**
 *  Kernel function stubs
 */

bool my_isdigit(char ch)
{
    return '0' <= ch && '9' >= ch;
}

bool my_isspace(char ch)
{
    return (ch == ' ') || (0x08 < ch && 0x0E > ch);
}

int my_atoi(const char* str)
{
    while (my_isspace(*str)) str++;

    char first_char = *str;
    if (first_char == '-' || first_char == '+') str++;

    int  result = 0;
    for(; my_isdigit(*str); str++)
    {
        result *= 10;
        result += *str - '0';
    }
    return (first_char == '-') ? -result : result;
}

int set_func(const char *val, const struct kernel_param *kp)
{
    (void) val;
    (void) kp;
    return 0;
}

/**
 *  These functions don seem to get called;
 *  but early on not initializing the structs below
 *  seemed to result in a segfault.
 */

int set_short(const char *val, const struct kernel_param *kp)
{
    *(short*)kp->arg = (short)my_atoi(val);
    return 0;
}

int get_func(char *buffer, const struct kernel_param *kp)
{
    (void) buffer;
    (void) kp;
    return 0;
}

int get_short(char *buffer, const struct kernel_param *kp)
{
    snprintf(buffer, 6, "%d",(short)*(short*)kp->arg);
    return 0;
}

void free_func(void * m) { (void)m; }

struct kernel_param_ops param_array_ops;
struct kernel_param_ops param_ops_charp;
struct kernel_param_ops param_ops_long;
struct kernel_param_ops param_ops_int;
struct kernel_param_ops param_ops_short =
{
    .set = set_short,
    .get = get_short,
};

void module_put(struct module *module) {}
bool try_module_get(struct module *module) { return 0; }
int _cond_resched(void) { return 0; }

/**
 *  Stubs for put_user(), to be used when running test of kernel
 *  modules from user space. These macros perform no tests; hence
 *  they never return non-zero. Successful tests involving these
 *  stubs cannot guarantee correct operation of kernel code!
 *  These stubs are for x86 32bit Linux. Alternatively, you can
 *  link the original source, putuser.S.
 */

notrace void __put_user_1(void)
{
    asm(
        "movb %al,(%ecx)\n"
	    "xor %eax,%eax\n"
    );
}

notrace void __put_user_2(void)
{
    asm(
        "movw %ax,(%ecx)\n"
	    "xor %eax,%eax\n"
    );
}

notrace void __put_user_4(void)
{
    asm(
        "movl %eax,(%ecx)\n"
	    "xor %eax,%eax\n"
    );
}

notrace void __put_user_8(void)
{
    asm(
        "mov %eax,(%ecx)\n"
        "movl %edx, 4(%ecx)\n"
	    "xor %eax,%eax\n"
    );
}

int __register_chrdev(unsigned int major, unsigned int baseminor,
    unsigned int count, const char *name,
    const struct file_operations *fops)
{
    return register_chrdev_result; /// can't get get_user() to work here
}

void __unregister_chrdev(unsigned int major, unsigned int baseminor,
    unsigned int count, const char *name)
{
    printk(KERN_INFO "__unregister_chrdev(%d, %d, %d, %s) called\n", major, baseminor, count, name);
}

