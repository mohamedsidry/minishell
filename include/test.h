#ifndef TEST_H
# define TEST_H

#include <assert.h>
#include "header.h"


# ifndef UNITTEST
#  define UNITTEST 0
# endif // UNITTEST
void modenotifier(void);
void echo(char *str);
void  print_arr(char **arr);
void display_env(t_list *envlst);

// UNIT TESTS 
void run_unit_tests(void);
void test_trimspaces(char *input, char *exp, char *(fun)(const char *));

#endif //TEST_H
