/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:27:24 by bford             #+#    #+#             */
/*   Updated: 2019/11/01 22:15:20 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

void	ft_print_time(struct stat buff)
{
	if (buff.st_mtime > 253234080000)
	{
		ft_putstr_num(ctime(&buff.st_mtime) + 4, 6);
		write(1, "  ", 2);
		ft_putstr_num(ctime(&buff.st_mtime) + 24, 5);
		write(1, " ", 1);
	}
	else if (buff.st_mtime - 15811200 > time(NULL) ||
	buff.st_mtime + 15811200 < time(NULL))
	{
		ft_putstr_num(ctime(&buff.st_mtime) + 4, 6);
		write(1, "  ", 2);
		ft_putstr_num(ctime(&buff.st_mtime) + 20, 4);
		write(1, " ", 1);
	}
	else
	{
		ft_putstr_num(ctime(&buff.st_mtime) + 4, 12);
		ft_putchar(' ');
	}
}
