/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_simlink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:21:14 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 18:55:11 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_print_simlink(struct stat buff, t_srcs *content)
{
	char	link[400];

	ft_bzero(link, 400);
	if (!lstat(content->path, &buff) && (buff.st_mode & S_IFMT) == S_IFLNK)
	{
		readlink(content->path, link, 399);
		ft_putstr(" -> ");
		ft_putstr(link);
	}
	return (1);
}
