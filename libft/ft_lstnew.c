/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:00:47 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/24 16:09:56 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	if (content != NULL)
	{
		new_list->content = malloc(content_size);
		if (new_list->content == NULL)
			return (NULL);
		new_list->content = ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	else
	{
		new_list->content = NULL;
		new_list->content_size = 0;
		new_list->next = NULL;
	}
	return (new_list);
}
