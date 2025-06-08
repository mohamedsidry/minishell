#include "../../include/header.h"

char *ft_concatenate(const char *s1, const char *s2, const char *sep)
{
    size_t len;
    size_t idx;
    char *result;

    len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(sep);
    result = ft_calloc(len + 1, sizeof(char));
    idx = ft_strlcpy(result, s1, ft_strlen(s1) + 1);
    idx += ft_strlcpy(result + idx, sep, ft_strlen(sep) + 1);
    ft_strlcpy(result + idx, s2, ft_strlen(s2) + 1);
    return (result);
}