/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l_or_not.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:54:41 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 20:28:16 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_print_l_or_not(const char *flag, t_srcs *content,
long int *ar)
{
	struct stat		buff;

	if (lstat(content->path, &buff))
		return (1);
	ft_print_flag_i(flag, buff);
	if (flag[25] || flag[28] || flag[21] || flag[27])
	{
		ft_print_filetype(buff);
		ft_print_rights(buff.st_mode);
		ft_print_acl(content->path);
		ft_print_nlink(buff, (int)ar[1]);
		ft_print_name_group(flag, buff, (int)ar[5], (int)ar[6]);
		ft_print_size(flag, buff, (int)ar[2]);
		ft_print_time(buff);
		ft_print_filename(flag, content);
		ft_print_simlink(buff, content);
	}
	else
		ft_print_filename(flag, content);
	ft_putchar('\n');
	return (0);
}
