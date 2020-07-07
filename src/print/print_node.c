//
// Created by youpaw on 17.03.2020.
//

#include "print.h"
#include "srcs.h"
#include <dirent.h>

static int get_dir_srcs(t_node *node, t_flags *flags)
{
	DIR *dir;

	if (!(dir = opendir(node->path)))
	{
		print_error(node->path);
		return (1);
	}
	node->srcs = get_srcs(dir, node->path, flags);
	closedir(dir);
	return (0);
}

void	print_node(t_node *node, t_flags *flags, t_print *attr)
{
	if (*node->path)
	{
		if (get_dir_srcs(node, flags))
			return ;
		print_dir_node(node, flags, attr);
	}
	else
	{
		print_file_node(node, flags, attr);
		attr->need_space = 1;
	}
}
