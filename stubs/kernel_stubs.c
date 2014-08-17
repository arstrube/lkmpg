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
    return 0;
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
    .free = free_func
};

void module_put(struct module *module) {}
bool try_module_get(struct module *module) { return 0; }
void __put_user_1(int a, int b) {}
int _cond_resched(void) { return 0; }

int __register_chrdev(unsigned int major, unsigned int baseminor,
    unsigned int count, const char *name,
    const struct file_operations *fops)
{
    return 0;
}

void __unregister_chrdev(unsigned int major, unsigned int baseminor,
    unsigned int count, const char *name) {}

