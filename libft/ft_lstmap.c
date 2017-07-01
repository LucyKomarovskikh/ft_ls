/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:19:05 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/03 21:33:43 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (lst != NULL)
	{
		new_list = f(lst);
		new_list->next = ft_lstmap(lst->next, f);
		return (new_list);
	}
	return (NULL);
}
