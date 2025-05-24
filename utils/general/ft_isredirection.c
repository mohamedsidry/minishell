#include "../../include/header.h"



int ft_isredirection(unsigned char c)
{
    return (c == REDIRECT_IN || c == REDIRECT_OUT);
}