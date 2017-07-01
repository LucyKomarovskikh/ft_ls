/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:32:21 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:38:01 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned char		a;

	a = (unsigned char)c;
	str = (unsigned const char *)s;
	while (n-- > 0)
	{
		if (*str++ == a)
			return ((void *)str - 1);
	}
	return (NULL);
}
