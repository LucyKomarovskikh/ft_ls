/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:16:10 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:36:24 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	char			*str;

	a = (unsigned char)c;
	str = (char *)b;
	while (len-- > 0)
		*str++ = a;
	return (b);
}
