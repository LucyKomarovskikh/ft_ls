/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:36:44 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:39:59 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;

	len_dst = ft_strlen(dst);
	if (size >= ft_strlen(dst) + 1)
	{
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
		return (len_dst + ft_strlen(src));
	}
	else
		return (size + ft_strlen(src));
}
