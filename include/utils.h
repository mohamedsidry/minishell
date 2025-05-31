#ifndef UTILS_H
# define UTILS_H

#include "typedef.h" 
#include <stddef.h>


// GENERAL HELPER FUNCTIONs !

void nullstr(char **strptr);
int ft_strcmp(char *str1, char *str2);
size_t ft_strlen(const char *str);
size_t ft_strlcpy(char *dst, const char *src, size_t n);
char *ft_strdup(const char *str);
char *ft_trimspaces(const char *str);
int ft_isspace(unsigned char  c);
void *ft_calloc(size_t count, size_t size);
void *ft_strchr(void *ptr, int byte);
char *ft_joinstrs(size_t count, ...);
char *ft_concatenate(const char *s1, const char *s2, const char *sep);
int ft_isquote(unsigned char c);
int ft_ispipe(unsigned char c);
int ft_isredirection(unsigned char c);
int ft_isunitbreaker(unsigned char c);
size_t skip_space(char *line, size_t *idx);
size_t ft_ismetachar(unsigned char c);
int ft_isampersand(unsigned char c);
int ft_issemicolon(unsigned char c);
int ft_isaflag(char *arg);
int ft_startwith(char *str, unsigned char c);

// LIST HELPER FUNCTIONs !

void listaddbacknode(t_list **chain, t_list *node);
void listaddfrontnode(t_list **chain, t_list *node);
t_list *listcreatenode(void *content);
void listdeletenode(t_list **node);
t_list *listiterate(t_list *listhead, void *(fun)(void *));
void listclearnodes(t_list **chain, void (del)(t_list **node));
t_list *listfindfirstnode(t_list *list);
t_list *listfindlastnode(t_list *list);
t_list *listiterate(t_list *listhead, void *(fun)(void *));
void *listtrimnodecontent(void *content);
size_t listsize(t_list *list);
int listvalidatenode(t_list *head, int (*valid)(t_list *node));
//  ENV VARIABLES HELPER FUNCTIONs

t_envnode *create_node(char *envp);
void delete_node(t_list **node);
void read_node(t_envnode *node);
char *getvalue(t_list *lst, char *key);
void setvalue(t_list *lst, char *key, char *newvalue);
char **env_serializer(t_list *envlst);



// validation functions 

void validator(t_list **tokens);
int validbalancedquotes(t_list *token);
int validsupportedmeta(t_list *token);

#endif // UTILS_H
