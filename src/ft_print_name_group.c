/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_name_group.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:41:52 by bford             #+#    #+#             */
/*   Updated: 2019/11/02 12:22:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

static int	ft_print_name(const char *flag, struct stat buff, int n)
{
	char *s;

	if (!flag[21])
	{
		s = (getpwuid(buff.st_uid))->pw_name;
		if (!flag[27] && s)
		{
			ft_putstr(s);
			while (n-- > (long)ft_strlen(s))
				ft_putchar(' ');
		}
		else
			ft_putnbr(buff.st_uid);
		ft_putstr("  ");
	}
	return (1);
}

static int	ft_print_group(const char *flag, struct stat buff, int g)
{
	char *s;

	if (flag[28])
		return (1);
	s = (getgrgid(buff.st_gid))->gr_name;
	if (!flag[27] && s)
	{
		ft_putstr(s);
		while (g-- > (long)ft_strlen(s))
			ft_putchar(' ');
	}
	else
		ft_putnbr(buff.st_gid);
	ft_putstr("  ");
	return (1);
}

void		ft_print_name_group(const char *flag,
								struct stat buff, int n, int g)
{
	flag[21] && flag[28] ? ft_putstr("  ") : 0;
	ft_print_name(flag, buff, n);
	ft_print_group(flag, buff, g);
}
