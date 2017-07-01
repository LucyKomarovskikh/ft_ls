/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:03:12 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:25:36 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	n;
	size_t	i;
	size_t	i1;

	i = 0;
	i1 = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (i == n)
		return (ft_strnew(n + 1));
	while (s[n - 1] == ' ' || s[n - 1] == '\n' || s[n - 1] == '\t')
		n--;
	if (!(new = ft_strnew(n - i)))
		return (NULL);
	while (i < n)
		new[i1++] = s[i++];
	new[i1] = '\0';
	return (new);
}
