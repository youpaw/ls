//
// Created by youpaw on 17.03.2020.
//

#include "print.h"

void	print_file_node(t_node *node, t_flags *flags, t_print *attr)
{
	char dir_path[MAX_PATHLEN];

	init_dir_path(dir_path, node->path);
	print_srcs(node->srcs, dir_path, flags);
	attr->need_space = 1;
}
