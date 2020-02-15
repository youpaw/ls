/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:30:50 by bford             #+#    #+#             */
/*   Updated: 2019/11/01 17:31:04 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_rights(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	if (mode & S_ISUID)
		ft_putchar(!(mode & S_IXUSR) ? 'S' : 's');
	else
		ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	if (mode & S_ISGID)
		ft_putchar(!(mode & S_IXGRP) ? 'S' : 's');
	else
		ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	if (mode & S_ISVTX)
		ft_putchar(!(mode & S_IXOTH) ? 'T' : 't');
	else
		ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}
