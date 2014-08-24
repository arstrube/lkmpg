/**
 *  putuser_wrapper.c: Wrapper to call put_user() stubst for testing
 *  without any need to include kernel headers.
 */
#include "putuser_wrapper.h"   /* Make sure this is okay */

#include <linux/module.h>      /* Needed by all modules */
#include <linux/kern_levels.h> /* Needed for KERN_INFO */
#include <linux/init.h>	       /* Needed for the macros */
#include <linux/fs.h>
#include <asm/uaccess.h>       /* for put_user */

extern int expected_long;
extern long expected_unsigned_long;
extern long long expected_long_long;
extern unsigned long long expected_unsigned_long_long;

/** wrappers for testing */

int put_user_wrapper_1s(char source, char *target)
{
    return put_user(source, target);
}

int put_user_wrapper_1u(unsigned char source, unsigned char *target)
{
    return put_user(source, target);
}

int put_user_wrapper_2s(short source, short *target)
{
    return put_user(source, target);
}

int put_user_wrapper_2u(unsigned short source, unsigned short *target)
{
    return put_user(source, target);
}

int put_user_wrapper_4s(long *target)
{
    return put_user(expected_long, target);
}

int put_user_wrapper_4u(unsigned long *target)
{
    return put_user(expected_unsigned_long, target);
}

int put_user_wrapper_8s(long long *target)
{
    return put_user(expected_long_long, target);
}

int put_user_wrapper_8u(unsigned long long *target)
{
    return put_user(expected_unsigned_long_long, target);
}
