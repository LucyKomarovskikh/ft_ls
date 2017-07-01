/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:13:44 by lkomarov          #+#    #+#             */
/*   Updated: 2017/01/18 15:13:47 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *chr)
{
	int	i;

	i = 0;
	while (*chr != '\0')
	{
		if (*chr <= 0x7F)
			i++;
		else if (*chr <= 0x7FF)
			i = i + 2;
		else if (*chr <= 0xFFFF)
			i = i + 3;
		else if (*chr <= 0x10FFFF)
			i = i + 4;
		chr++;
	}
	return (i);
}
