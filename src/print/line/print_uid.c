//
// Created by slavanya on 30.03.2020.
//

#include <print.h>
#include <libft.h>
#include <print_line.h>

void	print_uid(char *uid, int max_uid)
{
	print_col(uid, (int (*)(void *)) &ft_putstr, max_uid + LN_PADDING);
}