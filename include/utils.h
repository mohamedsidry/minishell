#ifndef UTILS_H
# define UTILS_H

void nullstr(char **strptr);
void ft_isexit(char *input);
int ft_strcmp(char *str1, char *str2);
size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t n);
char *ft_strdup(const char *str);
char *ft_trimspaces(const char *str);
int ft_isspace(int c);
void proreadline(char *prompt, char **strptr);

#endif // UTILS_H
