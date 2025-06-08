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
void display_tokens(t_list *lst);
void display_commands(t_list *commands);

// UNIT TESTS 
void run_unit_tests(void);
void test_trimspaces(char *input, char *exp, char *(fun)(const char *));

typedef enum s_jobcontext 
{
    DEFAULT,
    CMD,
    CMDARG,
    INFILE,
    OUTFILE,
    APPENDFILE,
    LIMIT,
    REDIRECTION,
} t_jobcontext;

// 
void test_is_builtin(void);
void test_builtin_pwd(void);
void test_builtin_echo(void);

// Helper macros for testing
# define TEST_ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            printf("❌ FAIL: %s\n", message); \
            exit(1); \
        } \
    } while(0)

# define TEST_PASS(message) \
    printf("✅ PASS: %s\n", message)
// 

#endif //TEST_H
