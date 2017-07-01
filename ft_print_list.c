/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int		ft_get_total(t_list *entry)
{
	t_list			*temp;
	unsigned int	total;
	t_st			*node;

	total = 0;
	temp = entry;
	while (temp != NULL)
	{
		node = temp->content;
		total += node->total;
		temp = temp->next;
	}
	return (total);
}

void				ft_print_total(t_list *entry)
{
	int				total;
	t_list			*temp;

	temp = entry;
	total = ft_get_total(temp);
	if (total == 0)
	{
		if (temp)
			ft_printf("total %d\n", total);
	}
	else
		ft_printf("total %d\n", total);
}

unsigned int		ft_w(t_list *lst, int fl)
{
	t_list			*temp;
	unsigned int	b;
	unsigned int	t;
	char			*a;
	t_st			*n;

	b = 0;
	temp = lst;
	while (temp != NULL)
	{
		n = temp->content;
		if (fl < 3)
		{
			fl == 1 ? (a = ft_strdup(ft_us(n->st_uid))) :
				(a = ft_strdup(ft_gr(n->g_id)));
			t = ft_strlen(a);
		}
		else
			fl == 3 ? t = ft_intcount(n->size) :
				(t = ft_intcount(n->nlink));
		if (b <= t)
			b = t;
		temp = temp->next;
	}
	return (b);
}

void				ft_pr_l(t_list *entry, int f)
{
	char			buf[1024];
	t_st			*n;
	size_t			l;

	n = entry->content;
	if (f > 2)
	{
		l = readlink(ft_strjoin(ft_strjoin(n->pname, "/"), n->name),
				buf, sizeof(buf));
		buf[l] = '\0';
		ft_printf("%s -> %s\n", n->name, buf);
	}
	else
		ft_printf("%s\n", n->name);
}

void				ft_print_list(t_list *entry, int flag)
{
	t_list			*temp;
	t_st			*n;

	temp = entry;
	flag < 0 ? (flag = -(flag)) : flag;
	while (flag >= 10)
		flag -= 10;
	if (flag > 2)
		ft_print_total(temp);
	while (temp != NULL)
	{
		n = temp->content;
		if (flag > 2)
		{
			ft_get_type(n->mode);
			ft_get_rights(n->mode);
			ft_printf("%*d ", ft_w(entry, 4), n->nlink);
			ft_printf("%-*s  ", ft_w(entry, 1), ft_us(n->st_uid));
			ft_printf("%*s  ", ft_w(entry, 2), ft_gr(n->g_id));
			ft_printf("%*lld ", ft_w(entry, 3), n->size);
			ft_get_time(n->time);
		}
		S_ISLNK(n->mode) ? ft_pr_l(temp, flag) : ft_printf("%s\n", n->name);
		temp = temp->next;
	}
}
