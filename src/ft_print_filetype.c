/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_filetype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:24:44 by bford             #+#    #+#             */
/*   Updated: 2019/11/01 17:24:59 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_filetype(struct stat buff)
{
	if ((buff.st_mode & S_IFMT) == S_IFDIR)
		write(1, "d", 1);
	else if ((buff.st_mode & S_IFMT) == S_IFCHR)
		write(1, "c", 1);
	else if ((buff.st_mode & S_IFMT) == S_IFBLK)
		write(1, "b", 1);
	else if ((buff.st_mode & S_IFMT) == S_IFSOCK)
		write(1, "s", 1);
	else if ((buff.st_mode & S_IFMT) == S_IFLNK)
		write(1, "l", 1);
	else
		write(1, "-", 1);
}
