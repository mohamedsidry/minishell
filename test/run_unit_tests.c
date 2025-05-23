#include "../include/header.h"



void run_unit_tests(void)
{
    if (DEBUGMODE && UNITTEST)
    {
        printf("\t\t\t\t⚒️ \033[1;37m RUNNING UNIT TESTS \033[0m⚒️\t\n​");
        test_trimspaces("\n\t\n\v\f\r   test \n", "test", ft_trimspaces);
    }

}




void test_trimspaces(char *input, char *exp, char *(fun)(const char *))
{
    char *result;

    result = fun(input);
    if (ft_strcmp(exp, result) != 0)
    {
        fprintf(stderr, "\033[1;31m\t\tUnit Test\033[0m : Test failed for '\033[1;36m%s\033[0m'\n",__func__);
        fprintf(stderr, "Expected: \"%s\"\nGot: \"%s\"\n", exp, result);
        assert(0);  // force a crash for test frameworks
    }
    else
    {
        fprintf(stdout, "\033[1;32m\t\tUnit Test\033[0m : Test Passed for '\033[1;36m%s\033[0m'\n",__func__);
        free(result);
    }
}