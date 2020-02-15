/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:35:42 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 18:33:14 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_init_params(t_nodes *node, char *argv)
{
	struct stat	buff;

	node->path = ft_strdup(argv);
	if (!node->path)
		exit(12);
	node->error = NULL;
	node->next = NULL;
	lstat(argv, &buff);
	node->time_mod = buff.st_mtime;
}

t_nodes			*ft_new_node(char *argv, const char *flags)
{
	t_nodes		*node;
	DIR			*dir;

	if (!(dir = opendir(argv)))
		return (ft_handle_error(errno, argv));
	if (!(node = (t_nodes*)malloc(sizeof(t_nodes))))
		exit(12);
	ft_init_params(node, argv);
	if (ft_strcmp(argv, "/"))
		node->content = ft_srcs_list(dir, argv, flags);
	else
		node->content = ft_srcs_list(dir, "", flags);
	closedir(dir);
	return (node);
}
