/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:52:13 by bterral           #+#    #+#             */
/*   Updated: 2022/04/26 16:07:53 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define UPPER "0123456789ABCDEF"
# define LOWER "0123456789abcdef"
# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		ft_bzero(void *str, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memchr( const void *src, int c, size_t n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *str, int character);
char		*ft_strrchr(const char *str, int character);
int			ft_strncmp(const char *str1, const char *str2, size_t num);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *str);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
void		*calloc(size_t nmemb, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/// ADDED FOR MINISHELL ///

char		**ft_split_piscine(char *str, char *charset);
int			ft_size_split(char *str, char *charset, int index);
int			ft_strcmp(const char *str1, const char *str2);

/// FT_DPRINTF.C ///

int			ft_dprintf(int fd, const char *input, ...);
int			get_print_size(const char *str, va_list args, int fd);
int			handle_variable(char c, va_list	args, int fd);
int			ft_putnbr_base_ll(unsigned long long nbr, char *base, int fd);
int			ft_putnbr_base_uint(unsigned int nbr, char *base, int fd);
int			handle_putint(int nb, int fd);
int			handle_putunsignedint(unsigned int nb, int fd);
int			handle_char(char c, int fd);
int			handle_string(char *str, int fd);

/// GET_NEXT_LINE ///

char		*get_next_line(int fd);
char		*free_static(char **str);

#endif
