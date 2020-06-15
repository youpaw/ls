//
// Created by youpaw on 27.03.2020.
//

#include <zconf.h>
#include "print_col.h"

void walk_srcs_col(t_avl *srcs, char *path, t_print_col *attr)
{
	if (!srcs)
		return ;
	walk_srcs_col(srcs->left, path, attr);
	print_src(srcs->content, path, attr);
	walk_srcs_col(srcs->right, path, attr);
}