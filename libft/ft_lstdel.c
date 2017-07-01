/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 20:03:04 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/03 21:37:48 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !(*alst))
		return ;
	if ((*alst)->next != NULL)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
