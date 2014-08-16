/**
 *  user_stubs.h
 */

 #ifndef USER_STUBS_H
 #define USER_STUBS_H

char* printk_get_loglevel(void);
char* printk_get_message(void);
void  printk_reset(void);
int   test_printf (const char * fmt, ...);
int   test_snprintf (char* buf, unsigned long n, const char * fmt,...);

#endif
