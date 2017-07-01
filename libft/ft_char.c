/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 20:45:37 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/24 20:47:21 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char(unsigned long long a)
{
	a = (signed char)a;
	if (g_str->fl_min == 0)
		g_str->fl_z == 1 ? ft_fill(0, g_str->w - 1) :
		ft_fill(1, g_str->w - 1);
	g_count += write(1, &a, 1);
	if (g_str->fl_min == 1)
		ft_fill(1, g_str->w - 1);
	return (0);
}
