/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:27:50 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/23 18:31:59 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ARG va_arg(*arg, unsigned int)

t_fmt					*g_str;
unsigned int			g_count_i;

t_fmt					*ft_create_new(void)
{
	g_str = (t_fmt *)malloc(sizeof(t_fmt));
	if (g_str)
	{
		g_str->fl_pl = 0;
		g_str->fl_min = 0;
		g_str->fl_ht = 0;
		g_str->fl_z = 0;
		g_str->fl_sp = 0;
		g_str->l = 0;
		g_str->pr = 1;
		g_str->w = 0;
		g_str->t = 0;
		g_str->pr_spec = 0;
		g_str->star_w = 0;
		g_str->star_pr = 0;
	}
	return (g_str);
}

void					ft_check_fmt(const char *format)
{
	g_str = ft_create_new();
	if (g_str)
	{
		ft_first_flag(format);
		g_str->t = format[g_count_i];
	}
}

void					ft_ull(unsigned long long *arg)
{
	g_str->pr < 0 ? ((g_str->pr = 1) &&
		(g_str->pr_spec = 0)) : g_str->pr;
	g_str->w < 0 ? ((g_str->w = -(g_str->w)) &&
			(g_str->fl_min = 1)) : g_str->w;
	(g_str->t == 'O' || g_str->t == 'D') ? g_str->l = "l" : g_str->l;
	if (ft_check_lt(g_str->t, 0) == 1)
		ft_ixo(*arg);
	else if (g_str->t == 'U')
		ft_pr_s(ft_all_toa(*arg, 10));
	else
		ft_char(g_str->t);
}

void					ft_pr_struct(va_list *arg)
{
	unsigned long long	temp;

	if (g_str->star_w > 0)
		g_str->star_w == 1 ? g_str->w = ARG : ARG;
	if (g_str->star_pr > 0)
		g_str->star_pr == 1 ? g_str->pr = ARG : ARG;
	if (g_str->t != '%')
	{
		if ((g_str->t == 's') && (g_str->l == NULL
					|| (ft_strcmp(g_str->l, "l") != 0)))
			ft_str(va_arg(*arg, char *));
		else if ((g_str->t == 'c' && g_str->l != NULL &&
					(ft_strcmp(g_str->l, "l") == 0)) || g_str->t == 'C')
			ft_putwchar(va_arg(*arg, wchar_t));
		else if ((g_str->t == 's' && g_str->l != NULL &&
					(ft_strcmp(g_str->l, "l") == 0)) || g_str->t == 'S')
			ft_wchar_str(va_arg(*arg, wchar_t*));
		else
		{
			temp = va_arg(*arg, unsigned long long);
			ft_ull(&temp);
		}
	}
	else if (g_str->t == '%')
		ft_char('%');
}

int						ft_printf(const char *format, ...)
{
	va_list				ap;

	g_count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			g_count += write(1, format, 1);
			format++;
		}
		else if (*format == '%' && *(format + 1) == '\0')
			return (0);
		else
		{
			ft_check_fmt(format + 1);
			ft_pr_struct(&ap);
			format = format + g_count_i + 2;
			g_count_i = 0;
		}
	}
	va_end(ap);
	return (g_count);
}
