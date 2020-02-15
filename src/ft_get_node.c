/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:27:13 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 21:50:24 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_add_file_node(t_nodes **head, char *argv, int type,
								const char *flags)
{
	t_nodes		*node;
	t_srcs		*new;

	node = *head;
	while (node && node->path)
		node = node->next;
	if (!node)
	{
		if (!(node = (t_nodes*)malloc(sizeof(t_nodes))))
			exit(12);
		node->path = NULL;
		node->error = NULL;
		node->time_mod = 0;
		node->content = NULL;
		node->next = NULL;
		ft_add_node(head, node, flags);
	}
	new = ft_srcs_new(argv, type, NULL);
	ft_add_srcs(&node->content, &new, flags);
}

void			ft_get_node(t_nodes **head, char *argv, char *flags)
{
	int			type;
	struct stat buff;

	if (flags[25] || flags[28] || flags[21] || flags[27])
		lstat(argv, &buff);
	else if (stat(argv, &buff))
	{
		errno = 0;
		lstat(argv, &buff);
	}
	if (errno)
	{
		ft_add_node(head, ft_handle_error(errno, argv), flags);
		return ;
	}
	type = buff.st_mode & S_IFMT;
	if (!flags[18] && type == S_IFDIR)
	{
		ft_add_node(head, ft_new_node(argv, flags), flags);
		return ;
	}
	else
		ft_add_file_node(head, argv, type, flags);
}
