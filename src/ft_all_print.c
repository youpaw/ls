/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:00:46 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 21:57:21 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_srcs(const char *flag, t_srcs *content,
		long int *ar)
{
	while (content)
	{
		if (ft_print_l_or_not(flag, content, ar) &&
			!flag[25] && !flag[28] && !flag[21] && !flag[27])
		{
			ft_print_filename(flag, content);
			ft_putchar('\n');
		}
		content = content->next;
	}
}

static void		ft_params_print(const char *flag, t_nodes *major_list,
		long int *ar)
{
	if (ar[4])
	{
		ft_putstr(major_list->path);
		ft_putstr(":\n");
	}
	else
		ar[4] = 1;
	if (major_list->content)
	{
		if (flag[25] || flag[28] || flag[21] || flag[27])
		{
			if (ft_know_max(major_list->content, ar))
				return ;
			ft_putstr("total ");
			ft_putnbr((int)ar[0]);
			ft_putchar('\n');
		}
		ft_print_srcs(flag, major_list->content, ar);
	}
}

static void		ft_handle_recursion(const char *flag, t_nodes **major_list,
		long int *ar)
{
	t_srcs		*srcs;
	t_nodes		*node;

	ft_params_print(flag, *major_list, ar);
	if (!(flag[10]) || (*major_list)->error)
	{
		if ((*major_list)->error)
			ft_putstr_fd((*major_list)->error, 2);
		ft_del_node(major_list);
		return ;
	}
	srcs = (*major_list)->content;
	while (srcs)
	{
		if (srcs->type_file == 4 && !ft_strequ(srcs->name, ".") &&
		!ft_strequ(srcs->name, ".."))
		{
			ft_putchar('\n');
			node = ft_new_node(srcs->path, flag);
			ft_handle_recursion(flag, &node, ar);
			ft_del_node(&node);
		}
		srcs = srcs->next;
	}
	ft_del_node(major_list);
}

void			ft_all_print(const char *flag, t_nodes **major_list)
{
	long int	ar[7];

	if (!(ar[4] = 0) && *major_list && (*major_list)->next)
		ar[4] = 1;
	while (*major_list)
	{
		if ((*major_list)->error)
		{
			ft_putstr_fd((*major_list)->error, 2);
			ft_del_node(major_list);
		}
		else
		{
			if (!(*major_list)->path)
			{
				ft_know_max((*major_list)->content, ar);
				ft_print_srcs(flag, (*major_list)->content, ar);
				ft_del_node(major_list);
			}
			else
				ft_handle_recursion(flag, major_list, ar);
			if (*major_list)
				ft_putchar('\n');
		}
	}
}
