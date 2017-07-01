/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:13:44 by lkomarov          #+#    #+#             */
/*   Updated: 2017/01/18 15:13:47 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7F)
		ft_putchar_c(chr);
	else if (chr <= 0x7FF)
	{
		ft_putchar_c((chr >> 6) + 0xC0);
		ft_putchar_c((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_c((chr >> 12) + 0xE0);
		ft_putchar_c(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar_c((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		ft_putchar_c((chr >> 18) + 0xF0);
		ft_putchar_c(((chr >> 12) & 0x3F) + 0x80);
		ft_putchar_c(((chr >> 6) & 0x3F) + 0x80);
		ft_putchar_c((chr & 0x3F) + 0x80);
	}
}

int		ft_wcharlen(wchar_t chr)
{
	int	i;

	i = 0;
	if (chr <= 0x7F)
		i++;
	else if (chr <= 0x7FF)
		i = i + 2;
	else if (chr <= 0xFFFF)
		i = i + 3;
	else if (chr <= 0x10FFFF)
		i = i + 4;
	return (i);
}

int		ft_wchrpres(wchar_t *str, int n)
{
	while (*str != '\0' && n >= ft_wcharlen(*str))
	{
		n = n - ft_wcharlen(*str);
		str++;
	}
	return (n);
}

void	ft_pr_wstring(wchar_t *str, int flag)
{
	int	n;
	int	temp;
	int	i;

	n = ft_wstrlen(str);
	g_str->pr < 0 ? ((g_str->pr = 1) &&
		(g_str->pr_spec = 0)) : g_str->pr;
	i = g_str->w;
	g_str->pr_spec && g_str->pr <= n ? (n = g_str->pr) : n;
	n = n - ft_wchrpres(str, n);
	temp = n;
	if (flag)
		g_str->fl_z == 1 ? ft_fill(0, i - n) : ft_fill(1, i - n);
	while (*str != '\0' && n >= ft_wcharlen(*str))
	{
		ft_putwchar(*str);
		n = n - ft_wcharlen(*str);
		str++;
	}
	if (!flag)
		ft_fill(1, i - temp);
}

int		ft_wchar_str(wchar_t *chr)
{
	int	c;

	c = 0;
	if (chr == NULL)
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
		g_str->fl_min == 1 ? ft_pr_wstring(chr, 0) : ft_pr_wstring(chr, 1);
	return (0);
}
