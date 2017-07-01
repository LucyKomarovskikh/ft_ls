/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 20:02:43 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 14:20:56 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordnb(char const *s, char c)
{
	int i;
	int sign;
	int count;

	i = 0;
	sign = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			sign = 1;
		}
		if (s[i] == c || s[i] == '\0')
		{
			count += (sign == 1) ? 1 : 0;
			sign = 0;
			i++;
		}
	}
	return (count);
}

int		ft_wordln(char const *s, int i, char c)
{
	int count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		p;

	i = 0;
	j = 0;
	if (!s || (res = malloc(sizeof(char*) * (ft_wordnb(s, c) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			p = 0;
			if ((res[j] = malloc(ft_wordln(s, i, c) + 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				res[j][p++] = s[i++];
			res[j++][p] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
