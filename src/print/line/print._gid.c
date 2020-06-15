//
// Created by slavanya on 30.03.2020.
//

#include <print.h>
#include <libft.h>
#include <print_line.h>

void 	print_gid(char *gid, int max_gid)
{
	print_col(gid, ft_putstr, max_gid + LN_PADDING);
}