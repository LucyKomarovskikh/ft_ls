/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define STR_TIME ((t_st *)(temp->content))->time_str.tv_sec

t_list		*ft_sort_again_r(t_list *lst)
{
	t_list	*temp;
	t_list	*temp2;
	t_st	*holder;

	temp = lst;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (STR_TIME == ((t_st *)(temp2->content))->time_str.tv_sec)
			{
				if (((t_st *)(temp->content))->nano_sec >=
						((t_st *)(temp2->content))->nano_sec)
				{
					holder = temp->content;
					temp->content = temp2->content;
					temp2->content = holder;
				}
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (lst);
}

t_list		*ft_sort_time_r(t_list *lst)
{
	t_list	*temp;
	t_list	*temp2;
	t_st	*holder;

	temp = lst;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (((t_st *)(temp->content))->time_str.tv_sec >=
					((t_st *)(temp2->content))->time_str.tv_sec)
			{
				holder = temp->content;
				temp->content = temp2->content;
				temp2->content = holder;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (lst);
}
