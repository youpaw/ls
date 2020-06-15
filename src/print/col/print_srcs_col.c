//
// Created by youpaw on 19.03.2020.
//

#include "print_col.h"
#include "str_lib.h"

void print_srcs_col(t_avl *srcs, char *path)
{
	t_print_col attr;

	init_col_attr(srcs, &attr);
	walk_srcs_col(srcs, path, &attr);
	if (attr.id || !attr.n)
		ft_putstr("\n");
	free(attr.widths);
}