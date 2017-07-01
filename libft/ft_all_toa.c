/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:42:33 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/24 20:45:32 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_get_length(unsigned long long nb, unsigned int base)
{
	unsigned int	length;

	length = 1;
	while (nb >= base)
	{
		length++;
		nb = nb / base;
	}
	return (length);
}

const char			*ft_all_toa(unsigned long long nb, unsigned int base)
{
	const char		*base_str = "0123456789ABCDEF";
	char			*str;
	unsigned int	length;

	g_str->t == 'x' || g_str->t == 'p' ?
		base_str = "0123456789abcdef" : base_str;
	if (g_str->pr == 0 && nb == 0 && (g_str->fl_ht != 1) && g_str->t != 'p')
		str = " ";
	else if (g_str->pr == 0 && nb == 0 && g_str->t == 'p')
		str = "0x";
	else
	{
		length = ft_get_length(nb, base);
		str = (char *)malloc(sizeof(char) * (length + 1));
		str[length] = '\0';
		while (0 < length--)
		{
			str[length] = base_str[nb % base];
			nb = nb / base;
		}
	}
	return (str);
}
