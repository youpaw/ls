//
// Created by youpaw on 17.03.2020.
//

#include "print_col.h"
#include "print_line.h"

void print_srcs(t_avl *srcs, char *path, t_flags *flags)
{
	if (!srcs)
		return ;
	if ((flags->print == f_col) || (flags->print == f_line))
		print_srcs_col(srcs, path);
//	else if (flags->print == f_line)
//		print_srcs_row(srcs);
	else
		print_srcs_line(srcs, path, flags);
}