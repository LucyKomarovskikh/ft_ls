/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_get_flag(char *arg)
{
	int			i;

	i = 1;
	if (ft_strchr(arg, 'a') != NULL)
		i++;
	if (ft_strchr(arg, 'l') != NULL && i != 1)
		i++;
	if (ft_strchr(arg, 'l') != NULL && i == 1)
		i = 4;
	if (ft_strchr(arg, 'r') != NULL)
		i += 10;
	if (ft_strchr(arg, 't') != NULL)
		i += 20;
	if (ft_strchr(arg, 'R') != NULL)
		i = -i;
	return (i);
}

int				ft_iter_dir(char *arg)
{
	struct stat	test;
	static int	n;
	int			i;

	i = 0;
	if (lstat(arg, &test) == -1)
	{
		while (arg[i] != '\0')
		{
			if (ft_strchr("-Ralnrt", arg[i]) == NULL)
				n = 1;
			i++;
		}
	}
	else
		n++;
	return (n);
}

int				ft_dir_loop(int argc, char **arg)
{
	int			i;
	int			n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		n = n + ft_iter_dir(arg[i]);
		i++;
	}
	return (n);
}

int				main(int argc, char **arg)
{
	int			i;
	int			f;
	char		*flag;
	int			n;

	i = 1;
	flag = ft_strdup("");
	if (argc > 1)
	{
		f = ft_err_loop(argc, arg, &flag);
		n = ft_dir_loop(argc, arg);
		while (i < argc)
		{
			n > 1 ? ft_ls(arg[i], ft_get_flag(flag), 1) :
				ft_ls(arg[i], ft_get_flag(flag), 0);
			i++;
		}
		if (n < 1 && f != -2)
			ft_ls(".", ft_get_flag(flag), 0);
	}
	else
		ft_ls(".", ft_get_flag(flag), 0);
	return (0);
}
