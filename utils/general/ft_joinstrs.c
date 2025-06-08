
#include "../../include/header.h"

static char *ft_concat(char *prev, const char *newstr);

char *ft_joinstrs(size_t count, ...)
{
    va_list arg;
    char *str;
    size_t idx;
    char *joined;

    idx = 0;
    joined = NULL;
    va_start(arg, count);
    while (idx < count)
    {
        str = va_arg(arg, char *);
        joined = ft_concat(joined, str);
        if (!joined)
            return (NULL);
        if (idx < count - 1)
        {
            joined = ft_concat(joined, ":");
            if (!joined)
                return (NULL);
        }else
        {
            joined = ft_concat(joined, "/");
            if (!joined)
                return (NULL);
        }
        idx++;
    }
    va_end(arg);
    return (joined);
}

static char *ft_concat(char *prev, const char *newstr)
{
    size_t idx;
    char *newjoined;

    idx = 0;
    if (!prev)
        return (ft_strdup(newstr));
    
    newjoined = ft_calloc((ft_strlen(prev) + ft_strlen(newstr) + 1), 1);
    if (!newjoined)
    {
        free (prev);
        return (NULL);
    }
    idx = ft_strlcpy(newjoined, prev, ft_strlen(prev) + 1);
    ft_strlcpy(newjoined + idx, newstr, ft_strlen(newstr) + 1);
    free (prev);
    return (newjoined);
}