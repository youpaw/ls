//
// Created by slavanya on 10.04.2020.
//

#include <libft.h>
#include <flags.h>
#include <print_line.h>

void 	print_total(t_flags *flags, size_t total)
{
	char data[5];

	ft_putstr("total ");
	if (flags->all[22])
	{
		get_human_readable(data, total);
		ft_putstr(data);
	}
	else
		ft_putnbr(total);
	ft_putchar('\n');
}