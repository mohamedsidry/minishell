#include "../../include/header.h"

void read_node(t_envnode *node)
{
    if (!node)
    {
        printf("EMPTY ENV NODE : no KEY no VALUE !\n");
        return ;
    }
    printf("KEY   : %s\n", node->key);
    printf("VALUE : %s\n", node->value);
    
}