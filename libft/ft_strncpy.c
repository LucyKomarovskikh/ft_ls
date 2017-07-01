/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:55:47 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 16:01:57 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *dest1;

	dest1 = dest;
	while ((*src != '\0') && (n > 0))
	{
		*dest1++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest1++ = '\0';
		n--;
	}
	return (dest);
}
