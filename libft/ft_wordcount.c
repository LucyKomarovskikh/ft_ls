/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 16:16:50 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/04 20:24:22 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char *str, char c)
{
	int	word_count;
	int	i;
	int	restart;

	i = 0;
	word_count = 0;
	restart = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == c) && restart == 1)
			restart = 0;
		if ((str[i] != c) && restart == 0)
		{
			restart = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}
