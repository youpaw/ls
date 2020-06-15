//
// Created by youpaw on 16.03.2020.
//

#include <nodes.h>
#include "mem_lib.h"

static t_node *init_file_node(void)
{
	t_node *new_node;

	new_node = ft_xmalloc(sizeof(t_node));
	ft_bzero(new_node->path, MAX_PATHLEN);
	ft_bzero(&new_node->info, sizeof(struct stat));
	new_node->srcs = NULL;
	return(new_node);
}

t_node 	*get_file_node(char *argv, struct stat info, t_flags *flags)
{
	static t_node *file_node;

	if (!file_node)
		file_node = init_file_node();
	file_node->srcs = ft_insert_avl(file_node->srcs,\
	ft_new_node(init_src(argv, info)), flags, \
	(int (*)(const void *, const void *, void *)) &cmp_srcs);
	if (!file_node->srcs->left && !file_node->srcs->right)
		return (file_node);
	return (NULL);
}