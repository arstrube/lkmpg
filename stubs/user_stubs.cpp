/**
 *  LKMPG "user-space" kernel stubs
 *  - do not require the inclusion of kernel headers
 *  - can be written in C++
 *  - do not need to be built with kernel make
 *  - can thus include StdCLib and any of CppUTest.
 */

#include "stubs/user_stubs.h"
#include <cstdarg>
#include "CppUTest/SimpleString.h"
#include "CppUTest/PlatformSpecificFunctions.h"


#define NBUF 10000L
static char log_buffer[NBUF];
static char * buffer_ptr = log_buffer;
static char log_level[3];

extern "C" {

    int printk (const char * fmt, ...)
    {
        SimpleString::StrNCpy(log_level, fmt, 2);
        fmt += 2;
        size_t reslen;
        size_t buflen = SimpleString::StrLen(log_buffer);
        if(NBUF > SimpleString::StrLen(fmt) + buflen) {
            va_list args;
            va_start(args, fmt);
            reslen = PlatformSpecificVSNprintf(buffer_ptr, NBUF-buflen, fmt, args);
            buffer_ptr += reslen;
        }
        return reslen;
    }

}

char* printk_get_message(void)
{
    return log_buffer;
}

char* printk_get_loglevel(void)
{
    return log_level;
}

void printk_reset(void) {
    buffer_ptr = log_buffer;
    *buffer_ptr = 0;
}

/**
 *  Strictly speaking, not a kernel stub, but we'll use it a lot
 */

int test_printf (const char * fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    return PlatformSpecificVSNprintf(log_buffer, NBUF, fmt, args);
}

int test_snprintf (char* buf, unsigned long n, const char * fmt,...)
{
    va_list args;
    va_start(args, fmt);
    return PlatformSpecificVSNprintf(buf, n, fmt, args);
}
