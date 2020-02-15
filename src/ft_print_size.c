/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:43:38 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 18:29:15 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_typesize(int t)
{
	if (t == 0)
		ft_putchar('B');
	else if (t == 1)
		ft_putchar('K');
	else if (t == 2)
		ft_putchar('M');
	else if (t == 3)
		ft_putchar('G');
	else if (t == 4)
		ft_putchar('T');
	ft_putchar(' ');
}

static void	ft_print_h(long long size)
{
	int i;
	int ost;

	i = 0;
	ost = 0;
	ft_putchar(' ');
	while (size > 999)
	{
		ost = size / 100 % 10;
		size /= 1000;
		i++;
	}
	if ((size > 9 && size < 100) || (!i && size < 10))
		ft_putchar(' ');
	if (!i && size < 10)
		ft_putchar(' ');
	ft_putnbr_ll(size);
	if (size < 10 && i)
	{
		ft_putchar(',');
		ft_putnbr_ll(ost);
	}
	ft_print_typesize(i);
}

void		ft_print_size(const char *flag, struct stat buff, int i)
{
	if ((buff.st_mode & S_IFMT) == S_IFBLK ||
	(buff.st_mode & S_IFMT) == S_IFCHR)
		ft_print_major_minor(buff);
	else if (flag[22])
		ft_print_h(buff.st_size);
	else
	{
		while (i-- > ft_lennbr(buff.st_size))
			ft_putchar(' ');
		ft_putnbr_ll(buff.st_size);
		ft_putchar(' ');
	}
}
