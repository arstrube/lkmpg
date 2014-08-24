/**
  *  putuser_wrapper.h
  */

#ifndef PUTUSER_WRAPPER_H
#define PUTUSER_WRAPPER_H

#include <linux/kern_levels.h> /* Needed for KERN_INFO */

void put_user_wrapper_1s(char source, char *target);
void put_user_wrapper_1u(unsigned char source, unsigned char *target);
void put_user_wrapper_2s(short source, short *target);
void put_user_wrapper_2u(unsigned short source, unsigned short *target);
void put_user_wrapper_4s(long *target);
void put_user_wrapper_4u(unsigned long *target);
void put_user_wrapper_8s(long long *target);
void put_user_wrapper_8u(unsigned long long *target);

#endif
