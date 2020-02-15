/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_major_minor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:36:44 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 21:32:36 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_major_minor(struct stat buff)
{
	int		maj;
	int		min;
	int		i;

	i = 3;
	maj = major(buff.st_rdev);
	min = minor(buff.st_rdev);
	while (i-- > ft_lennbr(maj))
		ft_putchar(' ');
	ft_putnbr(maj);
	ft_putstr(", ");
	i = 3;
	while (i-- > ft_lennbr(min))
		ft_putchar(' ');
	ft_putnbr(min);
	ft_putchar(' ');
}
