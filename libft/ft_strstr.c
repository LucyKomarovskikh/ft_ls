/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:38:32 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 16:21:22 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int found;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		found = 1;
		while (little[j] != '\0' && found == 1)
		{
			if (little[j] != big[i + j])
			{
				found = 0;
				break ;
			}
			j++;
		}
		if (found == 1)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
