/**
 *  getuser_wrapper.c: Wrapper to call put_user() stubst for testing
 *  without any need to include kernel headers.
 */
#include "getuser_wrapper.h"   /* Make sure this is okay */

#include <linux/module.h>      /* Needed by all modules */
#include <linux/kern_levels.h> /* Needed for KERN_INFO */
#include <linux/init.h>	       /* Needed for the macros */
#include <linux/fs.h>
#include <asm/uaccess.h>       /* for put_user */

extern unsigned char actual_unsigned_char;
extern unsigned char expected_unsigned_char;
extern char actual_char;
extern char expected_char;
extern unsigned short actual_unsigned_short;
extern unsigned short expected_unsigned_short;
extern short actual_short;
extern short expected_short;
extern long actual_long;
extern long expected_long;
extern unsigned long actual_unsigned_long;
extern unsigned long expected_unsigned_long;
extern long long actual_long_long;
extern long long expected_long_long;
extern unsigned long long actual_unsigned_long_long;
extern unsigned long long expected_unsigned_long_long;

/** wrappers for testing */

int get_user_wrapper_1s()
{
    return get_user(actual_char, &expected_char);
}

int get_user_wrapper_1u()
{
    return get_user(actual_unsigned_char, &expected_unsigned_char);
}

int get_user_wrapper_2s()
{
    return get_user(actual_short, &expected_short);
}


int get_user_wrapper_2u()
{
    return get_user(actual_unsigned_short, &expected_unsigned_short);
}

int get_user_wrapper_4s()
{
    return get_user(actual_long, &expected_long);
}

int get_user_wrapper_4u()
{
    return get_user(actual_unsigned_long, &expected_unsigned_long);
}
#if 0
int get_user_wrapper_8s()
{
    return get_user(actual_long_long, &expected_long_long);
}

int get_user_wrapper_8u()
{
    return get_user(actual_unsigned_long_long, &expected_unsigned_long_long);
}
#endif
