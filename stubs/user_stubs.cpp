/**
 *  LKMPG "user-space" kernel stubs
 *  - do not require the inclusion of kernel headers
 *  - can be written in C++
 *  - do not need to be built with kernel make
 *  - can thus include StdCLib and any of CppUTest.
 */

#include <cstdarg>
#include "CppUTest/SimpleString.h"
class TestPlugin; /// Should be in PlatformSpecificFuntions.h
#include "CppUTest/PlatformSpecificFunctions.h"

#define NBUF 5096L
static char log_buffer[NBUF];
static char log_level[3];

extern "C" {

    int printk (const char * fmt, ...)
    {
        va_list args;
        SimpleString::StrNCpy(log_level, fmt, 2);
        fmt += 2;
        va_start(args, fmt);
        return PlatformSpecificVSNprintf(log_buffer, NBUF, fmt, args);
    }

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
