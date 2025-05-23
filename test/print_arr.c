#include "../include/header.h"

void  print_arr(char **arr)
{
    size_t idx;
    idx = 0;
    if (!arr || !(*arr))
    {
        printf("Empty Array !\n");
        return ;
    }
    while (arr[idx])
    {
        printf("[%lu] : %s\n", idx, arr[idx]);
        idx++;
    }
}