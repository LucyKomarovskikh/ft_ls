/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ixo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:14:55 by lkomarov          #+#    #+#             */
/*   Updated: 2017/01/09 20:14:59 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		g_count = 0;

int					ft_convert(unsigned long long *n)
{
	ptrdiff_t		t;

	t = 0;
	if (g_str->l && g_str->t != 'U' && g_str->t != 'p')
	{
		if (ft_strcmp(g_str->l, "hh") == 0)
			IF_INT(g_str->t) ? (t = (signed char)*n) :
				(*n = (unsigned char)*n);
		if (ft_strcmp(g_str->l, "h") == 0)
			IF_INT(g_str->t) ? (t = (short)*n) : ft_assign_i(n, 1);
		if (ft_strcmp(g_str->l, "ll") == 0)
			IF_INT(g_str->t) ? (t = (long long)*n) : *n;
		if (ft_strcmp(g_str->l, "l") == 0)
			IF_INT(g_str->t) ? (t = (long)*n) : ft_assign_i(n, 2);
		if (ft_strcmp(g_str->l, "j") == 0)
			IF_INT(g_str->t) ? (t = (intmax_t) * n) : ft_assign_i(n, 3);
		if (ft_strcmp(g_str->l, "z") == 0)
			IF_INT(g_str->t) ? (t = (ptrdiff_t)*n) : ft_assign_i(n, 4);
		if (ft_strcmp(g_str->l, "L") == 0)
			IF_INT(g_str->t) ? (t = (int)*n) : ft_assign_i(n, 5);
	}
	else if (!g_str->l && g_str->t != 'U' && g_str->t != 'p')
		(IF_INT(g_str->t)) ? (t = (int)*n) : ft_assign_i(n, 5);
	(IF_INT(g_str->t)) ? *n = t : t;
	return (t >= 0 ? 1 : 0);
}

void				ft_ht(char *str, char c)
{
	if (IF_WRITE_C && (IF_INT(g_str->t)))
		g_count += write(1, &c, 1);
	ft_pr_ht(str);
}

void				ft_notap(unsigned long long i, int length, int base)
{
	int				d_num;
	char			c;
	char			*str;

	i = (ft_assing_c(&c, ft_convert(&i)) * i);
	(c == '-') && (length == g_str->w) ? length-- : length;
	(g_str->fl_pl == 1 && c != '-') ? c = '+' : c;
	str = ft_strdup(ft_all_toa(i, base));
	d_num = ft_d_num(str);
	(!IF_INT(g_str->t) && (g_str->fl_ht == 1) && (g_str->t != 'o'))
		|| (g_str->t == 'p') ? length = length - 2 : length;
	if ((g_str->pr_spec == 1 || g_str->fl_z == 0))
	{
		g_str->pr == 0 ? g_str->pr++ : g_str->pr;
		g_str->pr > d_num ? ft_fill(1, length - g_str->pr) :
			ft_fill(1, length - d_num);
		ft_ht(str, c);
		ft_fill(0, (g_str->pr) - d_num);
	}
	else if (g_str->fl_z == 1)
	{
		ft_ht(str, c);
		ft_fill(0, length - d_num);
	}
	ft_pr_s(str);
}

void				ft_tap(unsigned long long i, int length, unsigned int base)
{
	int				d_num;
	int				check;
	char			c;
	char			*str;

	check = 0;
	i = (ft_assing_c(&c, ft_convert(&i)) * i);
	str = ft_strdup(ft_all_toa(i, base));
	(!IF_INT(g_str->t) && (g_str->fl_ht == 1) && (g_str->t != 'o')) ||
		(g_str->t == 'p') ? length = length - 2 : length;
	d_num = ft_d_num(str);
	(c == '-') && (length == g_str->w) ? length-- : length;
	(g_str->fl_pl == 1 && c != '-') ? c = '+' : c;
	ft_pr_ht(str);
	if (IF_WRITE_C && (IF_INT(g_str->t)))
		g_count += write(1, &c, 1);
	if (g_str->pr > d_num)
		check = ft_fill(0, g_str->pr - d_num);
	ft_pr_s(str);
	if (check + d_num < length)
		ft_fill(1, length - (check + d_num));
}

int					ft_ixo(unsigned long long n)
{
	int				length;
	unsigned int	base;

	base = 10;
	g_str->t == 'x' || g_str->t == 'X' || g_str->t == 'p' ? base = 16 : base;
	g_str->t == 'o' || g_str->t == 'O' ? base = 8 : base;
	length = g_str->w;
	if (g_str->t == 'c' || g_str->t == 'C')
	{
		ft_char(n);
		return (1);
	}
	if (n == 0 && g_str->pr == 0 && g_str->w == 0)
	{
		if (((g_str->t == 'o' || g_str->t == 'O') && g_str->fl_ht != 1) ||
				g_str->t == 'x' || g_str->t == 'X' || g_str->t == 'd' ||
				g_str->t == 'u' || g_str->t == 'i')
			return (0);
	}
	if ((g_str->fl_pl == 1 || g_str->fl_sp == 1) && g_str->w > 0 &&
			(IF_INT(g_str->t)))
		length--;
	g_str->fl_min == 0 ? ft_notap(n, length, base) : ft_tap(n, length, base);
	return (0);
}
