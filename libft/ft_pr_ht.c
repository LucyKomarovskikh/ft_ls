/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr_ht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:09:00 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/23 18:09:04 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pr_ht(char *str)
{
	if ((g_str->fl_ht == 1 && *str != '0') || g_str->t == 'p')
	{
		if (ft_strcmp("0x", str) != 0)
			g_str->t == 'p' ? (g_str->t = 'x') : g_str->fl_ht;
		if (g_str->t == 'x' || g_str->t == 'X')
		{
			g_count += write(1, "0", 1);
			g_count += write(1, &g_str->t, 1);
		}
		else if (g_str->t == 'o' || g_str->t == 'O')
			g_count += write(1, "0", 1);
	}
}
