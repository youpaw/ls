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

void 	print_size(struct stat info, t_max_values max, t_flags *flags)
{
	char	data[5];

	if (S_ISBLK(info.st_mode) || S_ISCHR(info.st_mode))
	{
		print_col_right((void *)((size_t) major(info.st_rdev)), \
        (int (*)(void *)) &ft_putnbr, (int (*)(void *)) &ft_numlen, max.major);
		ft_putchar(',');
		print_col_right((void *)((size_t) minor(info.st_rdev)), \
        (int (*)(void *)) &ft_putnbr, (int (*)(void *)) &ft_numlen, max.minor);
	}
	else if (flags->all[22])
	{
		get_human_readable(data, info.st_size);
		print_col_right(data, (int (*)(void *)) &ft_putstr, \
        	(int (*)(void *)) &ft_strlen, 4);
	}
	else
		print_col_right((void *)((size_t) info.st_size), \
		(int (*)(void *)) &ft_putnbr, (int (*)(void *)) &ft_numlen, max.size);
}