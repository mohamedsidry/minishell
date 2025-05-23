#include "../../include/header.h"


int ft_isunitbreaker(unsigned char c)
{
    return (c == PIPE || ft_isredirection(c) || ft_isspace(c));
}