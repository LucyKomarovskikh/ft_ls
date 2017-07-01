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

#include "ft_ls.h"

void				ft_ls_recursion(t_list *temp, char *pname, int flag, int i)
{
	while (temp != NULL)
	{
		if (ft_strcmp(((t_st *)(temp->content))->name, ".") != 0
				&& ft_strcmp(((t_st *)(temp->content))->name, "..") != 0)
		{
			if (S_ISDIR(((t_st *)(temp->content))->mode))
			{
				ft_printf("\n");
				ft_printf("%s:\n", ft_strjoin(ft_strjoin(pname, "/"),
							((t_st *)(temp->content))->name));
				ft_ls(ft_strjoin(ft_strjoin(pname, "/"),
							((t_st *)(temp->content))->name), flag, i);
			}
		}
		temp = temp->next;
	}
}

int					ft_pr_name(int i, char *pname)
{
	static int		first;

	first += 1;
	if (first == 1)
		i == 1 ? ft_printf("%s:\n", pname) : i;
	else
		i == 1 ? ft_printf("\n%s:\n", pname) : i;
	return (0);
}

void				hate_norm_even_more(char *pname, int fl, int i)
{
	if (errno == EACCES)
	{
		fl < 0 ? fl : ft_pr_name(i, pname);
		ft_printf("ft_ls: %s: %s\n", pname, strerror(errno));
	}
	errno = 0;
}

void				ft_ls(char *pname, int fl, int i)
{
	DIR				*entry;
	struct dirent	*name;
	struct stat		buf;
	t_list			*n;
	t_list			*e_list;

	e_list = NULL;
	entry = opendir(pname);
	hate_norm_even_more(pname, fl, i);
	if (entry)
	{
		name = readdir(entry);
		while (name != NULL)
		{
			lstat(ft_strjoin(ft_strjoin(pname, "/"), name->d_name), &buf);
			n = ft_lstnew(ft_new_con(&buf, name->d_name, pname), sizeof(t_st));
			ft_form_list(&e_list, n, ((t_st *)(n->content))->name, fl);
			name = readdir(entry);
		}
		i = ft_pr_name(i, pname);
		ft_sort_list(e_list, fl);
		ft_print_list(e_list, fl);
		closedir(entry);
		fl < 0 ? ft_ls_recursion(e_list, pname, fl, i) : i;
	}
}
