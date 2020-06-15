//
// Created by youpaw on 17.03.2020.
//
#include "print.h"
#include "str_lib.h"

static int	get_dir_path(t_src *src, char dir_path[MAX_PATHLEN])
{
	if ((src->info.st_mode & S_IFMT) == S_IFDIR && \
	!ft_strequ(".", src->name) && \
	!ft_strequ("..", src->name))
	{
		ft_strcat(dir_path, src->name);
		return (0);
	}
	return (1);
}

static void	clear_dir_path(t_src *src, char dir_path[MAX_PATHLEN])
{
	dir_path[ft_strlen(dir_path) - ft_strlen(src->name)] = '\0';
}

static void	walk_srcs(t_avl *srcs, char dir_path[MAX_PATHLEN], t_flags *flags, t_print *attr)
{
	t_node *node;

	if (!srcs)
		return ;
	walk_srcs(srcs->left, dir_path, flags, attr);
	if (!get_dir_path(srcs->content, dir_path))
	{
		node = get_dir_node(dir_path, ((t_src*)srcs->content)->info);
		print_node(node, flags, attr);
		del_node(&node);
		clear_dir_path(srcs->content, dir_path);
	}
	walk_srcs(srcs->right, dir_path, flags, attr);
}

static void	print_dir_head(char *path, t_flags *flags, t_print *attr)
{
	if (attr->need_space)
		ft_putstr("\n");
	if (attr->need_head || flags->all[10])
	{
		ft_putstr(path);
		ft_putendl(":");
		attr->need_space = 1;
	}
}

void	print_dir_node(t_node *node, t_flags *flags, t_print *attr)
{
	char dir_path[MAX_PATHLEN];

	print_dir_head(node->path, flags, attr);
	init_dir_path(dir_path, node->path);
	print_srcs(node->srcs, dir_path, flags);
	if (flags->all[10])
		walk_srcs(node->srcs, dir_path, flags, attr);
}
