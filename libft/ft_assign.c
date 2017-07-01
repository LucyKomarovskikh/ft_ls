/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:09:00 by lkomarov          #+#    #+#             */
/*   Updated: 2017/03/23 18:09:04 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_assing_c(char *c, int i)
{
	int n;

	if (i > 0)
	{
		*c = ' ';
		n = 1;
	}
	else
	{
		n = -1;
		*c = '-';
	}
	return (n);
}

void	ft_assign_i(unsigned long long *n, int i)
{
	if (i == 1)
		*n = (unsigned short)*n;
	if (i == 2)
		*n = (unsigned long)*n;
	if (i == 3)
		*n = (uintmax_t) * n;
	if (i == 4)
		*n = (size_t)*n;
	if (i == 5)
		*n = (unsigned int)*n;
}
