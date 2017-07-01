/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkomarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:17:33 by lkomarov          #+#    #+#             */
/*   Updated: 2016/10/06 15:35:51 by lkomarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_gr(gid_t st_gid)
{
	struct group	*gr_name;
	char			*name;

	gr_name = getgrgid(st_gid);
	name = gr_name->gr_name;
	return (name);
}

char				*ft_us(uid_t st_uid)
{
	struct passwd	*user_name;
	char			*name;

	user_name = getpwuid(st_uid);
	name = user_name->pw_name;
	return (name);
}

void				ft_get_type(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_printf("d");
	if (S_ISCHR(mode))
		ft_printf("c");
	if (S_ISBLK(mode))
		ft_printf("b");
	if (S_ISLNK(mode))
		ft_printf("l");
	if (S_ISSOCK(mode))
		ft_printf("s");
	if (S_ISFIFO(mode))
		ft_printf("p");
	if (S_ISREG(mode))
		ft_printf("-");
}

void				ft_get_rights(mode_t mode)
{
	((S_IRUSR & mode) == 0) ? ft_printf("-") : ft_printf("r");
	((S_IWUSR & mode) == 0) ? ft_printf("-") : ft_printf("w");
	((S_IXUSR & mode) == 0) ? ft_printf("-") : ft_printf("x");
	((S_IRGRP & mode) == 0) ? ft_printf("-") : ft_printf("r");
	((S_IWGRP & mode) == 0) ? ft_printf("-") : ft_printf("w");
	((S_IXGRP & mode) == 0) ? ft_printf("-") : ft_printf("x");
	((S_IROTH & mode) == 0) ? ft_printf("-") : ft_printf("r");
	((S_IWOTH & mode) == 0) ? ft_printf("-") : ft_printf("w");
	((S_ISVTX & mode) && (S_IXOTH & mode)) ? ft_printf("t ") : mode;
	(!(S_ISVTX & mode) && (S_IXOTH & mode)) ? ft_printf("x ") : mode;
	((S_ISVTX & mode) && !(S_IXOTH & mode)) ? ft_printf("T ") : mode;
	(!(S_ISVTX & mode) && !(S_IXOTH & mode)) ? ft_printf("- ") : mode;
}

void				ft_get_time(char *raw_time)
{
	char			*new_time;
	time_t			t;

	t = time(&t);
	new_time = ctime(&t);
	ft_printf("%s", ft_strsub(raw_time + 4, 0, 3));
	ft_printf("%3d", ft_atoi(raw_time + 8));
	if (ft_strcmp((new_time + 20), (raw_time + 20)) == 0)
		ft_printf(" %s ", ft_strsub(raw_time + 11, 0, 5));
	else
		ft_printf(" %5d ", ft_atoi(raw_time + 20));
}
