#ifndef TEST_H
# define TEST_H

#include <assert.h>


# ifndef UNITTEST
#  define UNITTEST 0
# endif // UNITTEST
void modenotifier(void);
void echo(char *str);


// UNIT TESTS 
void run_unit_tests(void);
void test_trimspaces(char *input, char *exp, char *(fun)(const char *));

#endif //TEST_H
