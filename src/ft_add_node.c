/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:35:24 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/29 22:03:21 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_check_flags(const t_nodes *n1, const t_nodes *n2,
		const char *flags)
{
	if (n1->error && !n2->error)
		return (1);
	if (!n1->error && n2->error)
		return (0);
	if (n1->error && n2->error)
	{
		if (ft_strcmp(n1->error, n2->error) < 0)
			return (1);
		return (0);
	}
	if (!n1->path && n2->path)
		return (1);
	if (n1->path && !n2->path)
		return (0);
	if (flags[33] && n1->time_mod != n2->time_mod)
	{
		if (flags[31] && n1->time_mod > n2->time_mod)
			return (0);
		if (!(flags[31]) && n1->time_mod < n2->time_mod)
			return (0);
		return (1);
	}
	return (-1);
}

static int	ft_cmp_node(t_nodes *n1, t_nodes *n2, const char *flags)
{
	int		res;

	if ((res = ft_check_flags(n1, n2, flags)) >= 0)
		return (res);
	if (!(res = ft_strcmp(n1->path, n2->path)))
		return (0);
	if (flags[31] && res < 0)
		return (0);
	if (!(flags[31]) && res > 0)
		return (0);
	return (1);
}

void		ft_add_node(t_nodes **head, t_nodes *new, const char *flags)
{
	t_nodes *temp;
	t_nodes *prev;

	temp = *head;
	prev = NULL;
	if (!new)
		return ;
	while (temp && ft_cmp_node(temp, new, flags))
	{
		prev = temp;
		temp = temp->next;
	}
	if (!prev)
	{
		new->next = temp;
		*head = new;
		return ;
	}
	prev->next = new;
	new->next = temp;
}

void		ft_del_node(t_nodes **nodes)
{
	t_nodes *next;

	if (!nodes || !*nodes)
		return ;
	next = (*nodes)->next;
	ft_del_srcs(&((*nodes)->content));
	if ((*nodes)->path)
		free((*nodes)->path);
	if ((*nodes)->error)
		free((*nodes)->error);
	free(*nodes);
	*nodes = next;
}
