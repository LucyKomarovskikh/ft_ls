/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 22:04:16 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 16:04:13 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*str;
	char		a;

	a = (char)c;
	str = (const char *)s;
	while (*str != '\0')
	{
		if (*str++ == a)
			return ((char *)str - 1);
	}
	if (a == '\0')
		return ((char *)str);
	return (NULL);
}
