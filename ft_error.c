/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_if_flag(char *arg, int ch)
{
	int			i;
	char		*contr_str;

	i = 1;
	contr_str = ft_strdup("Ralnrt");
	if (arg[0] == '-')
	{
		while (arg[i] != '\0')
		{
			if (ft_strchr(contr_str, arg[i]) == NULL)
			{
				ft_printf("ft_ls: illegal option -- %c\nusage: "
						"ft_ls [-Ralnrt] [file ...]\n", arg[i]);
				exit(0);
			}
			i++;
		}
	}
	else if (arg[0] != '-')
	{
		ft_printf("ft_ls: %s: %s\n", arg, strerror(errno));
		ch == 1 ? exit(0) : ch;
		return (0);
	}
	return (1);
}

int				ft_check_err(char *arg, int argc, int index)
{
	struct stat	test;
	static int	i;

	if (lstat(arg, &test) == -1)
	{
		if (i != 1)
		{
			if (ft_if_flag(arg, (argc - index)) == 1)
				return (1);
			else
			{
				i = 1;
				return (0);
			}
		}
		else
			ft_printf("ft_ls: %s: %s\n", arg, strerror(errno));
	}
	else
	{
		i = 1;
		if (!S_ISDIR(test.st_mode))
			return (2);
	}
	return (0);
}

int				ft_err_loop(int argc, char **arg, char **flag)
{
	int			i;
	int			f;

	i = 1;
	while (i < argc)
	{
		f = ft_check_err(arg[i], argc, i);
		errno = 0;
		if (f == 1)
			*flag = ft_strjoin(*flag, arg[i]);
		else if (f == 2)
			ft_print_file(arg[i], ft_get_flag(*flag));
		i++;
	}
	return (f);
}
