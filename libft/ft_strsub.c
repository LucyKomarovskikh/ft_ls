/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:11:25 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:30:00 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	if (s)
	{
		while (i < len)
		{
			new[i] = s[start];
			i++;
			start++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
