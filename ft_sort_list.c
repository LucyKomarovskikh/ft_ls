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

t_list		*ft_sort(t_list *lst)
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
			if (ft_strcmp(((t_st *)(temp->content))->name,
						((t_st *)(temp2->content))->name) >= 0)
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

t_list		*ft_sort_again(t_list *lst)
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
				if (((t_st *)(temp->content))->nano_sec <=
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

t_list		*ft_sort_time(t_list *lst)
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
			if (((t_st *)(temp->content))->time_str.tv_sec <=
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

t_list		*ft_sort_reverse(t_list *lst)
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
			if (ft_strcmp(((t_st *)(temp->content))->name,
						((t_st *)(temp2->content))->name) <= 0)
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

t_list		*ft_sort_list(t_list *lst, int flag)
{
	t_list	*result;

	if ((flag >= 10 && flag < 20) || (-(flag) >= 10 && -(flag) < 20))
		result = ft_sort_reverse(lst);
	else if ((flag >= 20 && flag < 30) || (-(flag) >= 20 && -(flag) < 30))
		result = ft_sort_again(ft_sort_time(lst));
	else if (flag >= 30 || -(flag) >= 30)
		result = ft_sort_again_r(ft_sort_time_r(lst));
	else
		result = ft_sort(lst);
	return (result);
}
