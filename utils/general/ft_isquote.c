#include "../../include/header.h"



int ft_isquote(unsigned char c)
{
    return (c == CHAR_SQUOTE || c == CHAR_DQUOTE || c == CHAR_BACKTICK);
}