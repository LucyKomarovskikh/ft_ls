/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_st		*ft_new_con(struct stat *buf, char *name, char *pathname)
{
	t_st	*new;

	new = (t_st *)malloc(sizeof(t_st));
	if (new && (buf != NULL))
	{
		new->name = ft_strdup(name);
		new->pname = ft_strdup(pathname);
		new->mode = buf->st_mode;
		new->nlink = buf->st_nlink;
		new->st_uid = buf->st_uid;
		new->g_id = buf->st_gid;
		new->size = buf->st_size;
		new->time_str = buf->st_mtimespec;
		new->nano_sec = buf->st_mtimespec.tv_nsec;
		new->time = ft_strdup(ctime(&(buf->st_mtimespec).tv_sec));
		new->total = buf->st_blocks;
	}
	return (new);
}

void		ft_form_list(t_list **e_list, t_list *node, char *name, int flag)
{
	flag < 0 ? flag = -(flag) : flag;
	while (flag > 10)
		flag -= 10;
	if (flag == 1 || flag == 4)
		name[0] == '.' ? free(node) : ft_lstadd(e_list, node);
	else
		ft_lstadd(e_list, node);
}
