/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 11:54:18 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:34:35 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *c;

	c = (char *)malloc(size + 1);
	if (!c)
		return (NULL);
	else
		ft_bzero(c, size + 1);
	return (c);
}
