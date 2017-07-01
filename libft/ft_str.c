/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:13:44 by lkomarov          #+#    #+#             */
/*   Updated: 2017/01/18 15:13:47 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pr_string(char *str, int flag)
{
	int	n;
	int	temp;
	int i;

	n = ft_strlen(str);
	i = g_str->w;
	g_str->pr < 0 ? ((g_str->pr = 1)
		&& (g_str->pr_spec = 0)) : g_str->pr;
	g_str->pr_spec && g_str->pr <= n ? (n = g_str->pr) : n;
	temp = n;
	if (flag)
		g_str->fl_z == 1 ? ft_fill(0, i - n) : ft_fill(1, i - n);
	while (n-- > 0)
	{
		g_count += write(1, str, 1);
		str++;
	}
	if (!flag)
		ft_fill(1, i - temp);
}

int		ft_str(char *s)
{
	int	c;

	c = 0;
	if (s == NULL)
	{
		if (g_str->pr_spec == 1)
		{
			g_str->fl_z == 1 ? c : (c = 1);
			ft_fill(c, g_str->w);
			return (0);
		}
		g_count += write(1, "(null)", 6);
		return (0);
	}
	else
		g_str->fl_min == 1 ? ft_pr_string(s, 0) : ft_pr_string(s, 1);
	return (0);
}
