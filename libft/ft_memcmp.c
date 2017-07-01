/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:31:01 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 16:25:06 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *str1;
	unsigned const char *str2;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((unsigned const char)*str1 - (unsigned const char)*str2);
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		n--;
	}
	return (0);
}
