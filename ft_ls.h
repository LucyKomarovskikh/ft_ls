/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct		s_stat
{
	char			*name;
	char			*pname;
	mode_t			mode;
	nlink_t			nlink;
	uid_t			st_uid;
	gid_t			g_id;
	off_t			size;
	struct timespec	time_str;
	long			nano_sec;
	unsigned int	total;
	char			*time;
}					t_st;

int					ft_get_flag(char *arg);
int					ft_iter_dir(char *arg);
int					ft_if_flag(char *arg, int ch);
int					ft_check_err(char *arg, int argc, int index);
int					ft_err_loop(int argc, char **arg, char **flag);
void				ft_print_file(char *name, int flag);
void				ft_pr_lf(char *name, int flag);
void				ft_get_time(char *raw_time);
void				ft_get_type(mode_t mode);
void				ft_get_rights(mode_t mode);
char				*ft_gr(gid_t st_gid);
char				*ft_us(uid_t st_uid);
void				ft_print_list(t_list *node, int flag);
t_list				*ft_sort_list(t_list *lst, int flag);
void				ft_form_list(t_list **e_list, t_list *node,
					char *name, int flag);
t_st				*ft_new_con(struct stat *buf, char *name, char *pathname);
void				ft_pr_l(t_list *entry, int f);
void				ft_ls(char *pathname, int flag, int i);
t_list				*ft_sort_time_r(t_list *lst);
t_list				*ft_sort_again_r(t_list *lst);

#endif
