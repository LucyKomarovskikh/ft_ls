/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:12:31 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:24:49 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*new_a;
	int		size;
	int		a;

	a = 0;
	size = ft_digitcount(n);
	if (size == 0)
		return (ft_strdup("-2147483648"));
	new_a = ft_strnew(size);
	if (!new_a)
		return (NULL);
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		a++;
	}
	while (size > 0)
	{
		new_a[size - 1] = '0' + (n % 10);
		n /= 10;
		size--;
	}
	if (a != 0)
		new_a[0] = '-';
	return (new_a);
}
