/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_pr_lf(char *name, int flag)
{
	char			buf[1024];
	size_t			l;

	if (flag == 4 || flag == 3)
	{
		l = readlink(ft_strjoin("/.", name), buf, sizeof(buf));
		buf[l] = '\0';
		ft_printf("%s -> %s\n", name, buf);
	}
	else
		ft_printf("%s\n", name, buf);
}

void				ft_print_file(char *name, int flag)
{
	struct stat		file;
	char			*time;

	lstat(name, &file);
	flag < 0 ? (flag = -(flag)) : flag;
	while (flag >= 10)
		flag -= 10;
	if (flag == 4 || flag == 3)
	{
		ft_get_type(file.st_mode);
		ft_get_rights(file.st_mode);
		ft_printf("%*d ", ft_digitcount(file.st_nlink));
		ft_printf("%-*s  ", ft_strlen(ft_us(file.st_uid)), ft_us(file.st_uid));
		ft_printf("%*s  ", ft_strlen(ft_gr(file.st_gid)), ft_gr(file.st_gid));
		ft_printf("%*lld ", ft_digitcount(file.st_size) - 1, file.st_size);
		time = ft_strdup(ctime(&(file.st_ctimespec).tv_sec));
		ft_get_time(time);
	}
	S_ISLNK(file.st_mode) ? ft_pr_lf(name, flag) : ft_printf("%s\n", name);
}
