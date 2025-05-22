#ifndef UTILS_H
# define UTILS_H

#include "typedef.h" 

// GENERAL HELPER FUNCTIONs !

void nullstr(char **strptr);
void ft_isexit(char *input);
int ft_strcmp(char *str1, char *str2);
size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t n);
char *ft_strdup(const char *str);
char *ft_trimspaces(const char *str);
int ft_isspace(int c);
void proreadline(char *prompt, char **strptr);
void *ft_calloc(size_t count, size_t size);
void *ft_strchr(void *ptr, int byte);
// LIST HELPER FUNCTIONs !

void listaddbacknode(t_list **chain, t_list *node);
void listaddfrontnode(t_list **chain, t_list *node);
t_list *listcreatenode(void *content);
void listdeletenode(t_list *node);
t_list *listiterate(t_list *listhead, void *(fun)(void *));
void listclearnodes(t_list **chain, void (del)(t_list *node));
t_list *listfindfirstnode(t_list *list);
t_list *listfindlastnode(t_list *list);
t_list *listiterate(t_list *listhead, void *(fun)(void *));
void *listtrimnodecontent(void *content);
size_t listsize(t_list *list);

//  ENV VARIABLES HELPER FUNCTIONs

t_envnode *create_node(char *envp);
void delete_node(t_list *node);
void read_node(t_envnode *node);


#endif // UTILS_H
