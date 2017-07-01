/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:45:22 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 16:03:10 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*strdup;
	int		i;

	i = (ft_strlen(s1) + 1);
	strdup = (char *)malloc(i);
	if (!strdup)
		return (NULL);
	while (i-- > 0)
		strdup[i] = s1[i];
	return (strdup);
}
