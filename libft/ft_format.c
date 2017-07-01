/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:50:16 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/24 21:01:22 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fmt *g_str;
unsigned int g_count_i = 0;

int			ft_check_lt(char type, int i)
{
	char	*check_str;

	if (i == 1)
		check_str = "hljztL";
	else
		check_str = "dDiuoOxXfFeEgGaAcCspn%";
	while (*check_str != '\0')
	{
		if (*check_str == type)
			return (1);
		check_str++;
	}
	return (0);
}

void		ft_fouth_length(const char *format)
{
	g_str->l = ft_strsub(format, 0, 1);
	g_count_i++;
	if (format[0] == 'h' && format[1] == 'h')
	{
		g_str->l = "hh";
		g_count_i++;
	}
	if (format[0] == 'l' && format[1] == 'l')
	{
		g_str->l = "ll";
		g_count_i++;
	}
}

void		ft_third_precision(const char *format)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	g_count_i++;
	g_str->pr_spec = 1;
	g_str->pr = 0;
	if (*format == '*')
	{
		g_str->star_pr = 1;
		IF_NBR(*(format + 1)) ? check++ : check;
		IF_NBR(*(format + 1)) ? g_str->star_pr++ : check;
		i++;
	}
	if (IF_NBR(*format) || check == 1 || *format == '0')
	{
		g_str->pr = ft_find_nbr(format + check);
		i = ft_intcount(g_str->pr);
		(*(format + i) == '*' && check != 1) ? (g_str->star_pr = 1) : i;
		(*(format + i) == '*' && check != 1) ? i++ : i;
	}
	g_count_i = (g_count_i + i + check);
	if (ft_check_lt(format[i + check], 1) == 1)
		ft_fouth_length(format + i + check);
}

void		ft_second_width(const char *format)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (*format == '*')
	{
		g_str->star_w = 1;
		IF_NBR(*(format + 1)) ? check++ : check;
		IF_NBR(*(format + 1)) ? g_str->star_w++ : check;
		i++;
	}
	if (IF_NBR(*format) || check == 1)
	{
		g_str->w = ft_find_nbr(format + check);
		i = ft_intcount(g_str->w);
		(*(format + i) == '*' && check != 1) ? (g_str->star_w = 1) : i;
		(*(format + i) == '*' && check != 1) ? i++ : i;
	}
	g_count_i = (g_count_i + i + check);
	if (*(format + i + check) == '.')
		ft_third_precision(format + i + check + 1);
	else if (ft_check_lt(format[i + check], 1) == 1)
		ft_fouth_length(format + i + check);
}

void		ft_first_flag(const char *format)
{
	while (IF_FLAG(*format))
	{
		if (*format == '-')
			g_str->fl_min = 1;
		if (*format == ' ')
			g_str->fl_sp = 1;
		if (*format == '+')
			g_str->fl_pl = 1;
		if (*format == '#')
			g_str->fl_ht = 1;
		if (*format == '0')
			g_str->fl_z = 1;
		format++;
		g_count_i++;
	}
	if (IF_NBR(*format) || *format == '*')
		ft_second_width(format);
	else if (*format == '.')
		ft_third_precision(format + 1);
	else if (ft_check_lt(*format, 1) == 1)
		ft_fouth_length(format);
}
