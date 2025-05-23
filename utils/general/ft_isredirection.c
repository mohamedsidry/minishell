#include "../../include/header.h"



int ft_isredirection(unsigned int c)
{
    return (c == REDIRECT_IN || c == REDIRECT_OUT);
}