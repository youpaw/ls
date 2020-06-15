//
// Created by slavanya on 30.03.2020.
//
#include <stdio.h>
#include <flags.h>
#include <sys/stat.h>
#include <zconf.h>
#include <print_line.h>
#include <print.h>
#include <libft.h>

//static char 	get_typesize(int type)
//{
//	if (type == 0)
//		return ('B');
//	else if (type == 1)
//		return ('K');
//	else if (type == 2)
//		return ('M');
//	else if (type == 3)
//		return ('G');
//	else if (type == 4)
//		return ('T');
//	return (' ');
//}
//
//static void		print_h_flag(size_t size)
//{
//	int		type;
//	int		rest;
//	char	date[5];
//
//	ft_bzero(date, 5);
//	type = 0;
//	while (size >= 1000)
//	{
//		rest = (size / 100) % 10;
//		size /= 1000;
//		type++;
//	}
//	if (size < 10 && type)
//	{
//		date[0] = size + '0';
//		date[1] = ',';
//		date[2] = rest + '0';
//		date[3] = get_typesize(type);
//		print_col(date, &ft_putstr, 4);
//		return ;
//	}
//	print_col_right(size, &ft_putnbr, &ft_numlen, 4);
//}

void 	print_size(struct stat info, t_max_values max, t_flags *flags)
{
	char	data[5];

	if (S_ISBLK(info.st_mode) || S_ISCHR(info.st_mode))
	{
		print_col_right(major(info.st_rdev), &ft_putnbr,
			&ft_numlen, max.major);
		ft_putchar(',');
		print_col_right(minor(info.st_rdev), &ft_putnbr,
			&ft_numlen, max.minor);
	}
	else if (flags->all[22])
	{
		get_human_readable(data, info.st_size);
		print_col_right(data, &ft_putstr, &ft_strlen, 4);
	}
	else
		print_col_right(info.st_size, &ft_putnbr, &ft_numlen,
				max.size);
}