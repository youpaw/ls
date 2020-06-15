//
// Created by youpaw on 16.03.2020.
//

#include "nodes.h"
#include "str_lib.h"
#include "mem_lib.h"

t_node	*get_dir_node(char *argv, struct stat info)
{
	t_node *new_node;

	new_node = (t_node*)ft_xmalloc(sizeof(t_node));
	new_node->info = info;
	ft_strcpy(new_node->path, argv);
	new_node->srcs = NULL;
	return(new_node);
}
