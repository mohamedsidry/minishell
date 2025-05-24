#include "../../include/header.h"



int ft_isquote(unsigned char c)
{
    return (c == S_QUOTE || c == D_QUOTE || c == BACKTICK);
}