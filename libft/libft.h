/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:43:41 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/04 20:19:28 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <stdint.h>
# include <stddef.h>

# define IF_FLAG(c) c == '-' || c == '+' || c == ' ' || c == '#' || c == '0'
# define IF_NBR(c) (c > 48 && c <= 57)
# define IF_INT(c) (c == 'd' || c == 'i' || c == 'D' || c == 'U')
# define IF_WRITE_C (g_str->fl_pl == 1 || g_str->fl_sp == 1 || c == '-')

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_format_string
{
	unsigned int	pr_spec;
	unsigned int	fl_min;
	unsigned int	fl_pl;
	unsigned int	fl_sp;
	unsigned int	fl_ht;
	unsigned int	fl_z;
	int				w;
	int				pr;
	char			*l;
	char			t;
	int				star_w;
	int				star_pr;
}					t_fmt;

extern unsigned int g_count;
extern unsigned int g_count_i;
extern t_fmt		*g_str;

char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
int					ft_digitcount(int i);
int					ft_wordcount(char *str, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **tlst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_memrcpy(void *dst, const void *src, size_t n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
					const char *little, size_t len);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_assign_i(unsigned long long *n, int i);
int					ft_assing_c(char *c, int i);
void				ft_pr_ht(char *str);
int					ft_find_nbr(const char *str);
int					ft_intcount(ptrdiff_t i);
int					ft_fill(int flag, int length);
const char			*ft_all_toa(unsigned long long nb, unsigned int base);
void				ft_tap(unsigned long long i, int length, unsigned int base);
void				ft_notap(unsigned long long i, int length, int base);
void				ft_pr_string(char *str, int flag);
void				ft_pr_s(const char *str);
int					ft_convert(unsigned long long *n);
int					ft_wstrlen(wchar_t *chr);
void				ft_putwchar(wchar_t chr);
void				ft_putchar_c(char c);
int					ft_wchar_str(wchar_t *chr);
int					ft_wchrpres(wchar_t *str, int n);
int					ft_d_num(char *str);
int					ft_check_lt(char type, int i);
void				ft_fouth_length(const char *format);
void				ft_third_precision(const char *format);
void				ft_second_width(const char *format);
void				ft_first_flag(const char *format);
int					ft_str(char *s);
int					ft_ixo(unsigned long long n);
void				ft_ull(unsigned long long *arg);
int					ft_char(unsigned long long a);
int					ft_wchar_str(wchar_t *chr);
t_fmt				*ft_create_new(void);
void				ft_check_fmt(const char *format);
void				ft_pr_struct(va_list *arg);
int					ft_printf(const char *format, ...);
#endif
