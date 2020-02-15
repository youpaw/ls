/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_i.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:30:41 by bford             #+#    #+#             */
/*   Updated: 2019/11/02 11:31:53 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_print_flag_i(const char *flag, struct stat buff)
{
	if (flag[23])
	{
		ft_putnbr(buff.st_ino);
		write(1, " ", 1);
	}
	return (1);
}
