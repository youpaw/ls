/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcs_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:53:26 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 22:02:04 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ft_check_flags(t_srcs *n1, t_srcs *n2, const char *flags)
{
	int				cmp;

	if (flags[33] && n1->time_mod != n2->time_mod)
	{
		if (flags[31] && n1->time_mod > n2->time_mod)
			return (1);
		if (!(flags[31]) && n1->time_mod < n2->time_mod)
			return (1);
		return (0);
	}
	if (!(cmp = ft_strcmp(n1->name, n2->name)))
		return (1);
	if (flags[31] && cmp < 0)
		return (1);
	if (!(flags[31]) && cmp > 0)
		return (1);
	return (0);
}

void				ft_add_srcs(t_srcs **head, t_srcs **new, const char *flags)
{
	t_srcs			*copy;
	t_srcs			*prev;

	copy = *head;
	prev = NULL;
	while (copy)
	{
		if (ft_check_flags(copy, *new, flags))
			break ;
		prev = copy;
		copy = copy->next;
	}
	if (!prev)
	{
		(*new)->next = copy;
		*head = *new;
		return ;
	}
	prev->next = *new;
	(*new)->next = copy;
}

void				ft_del_srcs(t_srcs **l)
{
	if (l && *l)
	{
		if ((*l)->next)
			ft_del_srcs(&((*l)->next));
		if ((*l)->name)
			free((*l)->name);
		if ((*l)->path)
			free((*l)->path);
		free(*l);
		*l = NULL;
	}
}

t_srcs				*ft_srcs_new(char *name, int type, char *path)
{
	t_srcs			*list;
	struct stat		buff;

	if (!(list = (t_srcs *)malloc(sizeof(t_srcs))))
		exit(12);
	if (path)
	{
		path = ft_strjoin(path, "/");
		list->path = ft_strjoin(path, name);
		if (path)
			free(path);
	}
	else
		list->path = ft_strdup(name);
	list->name = ft_strdup(name);
	if (!list->name || !list->path)
		exit(12);
	list->type_file = type;
	lstat(list->path, &buff);
	list->time_mod = buff.st_mtime;
	list->next = NULL;
	return (list);
}

t_srcs				*ft_srcs_list(DIR *dirp, char *path, const char *flags)
{
	t_srcs			*new;
	t_srcs			*head;
	struct dirent	*dirread;

	head = NULL;
	while ((dirread = readdir(dirp)))
	{
		if ((flags[15]) || (flags[1] && ft_strcmp(dirread->d_name, ".") &&
		ft_strcmp(dirread->d_name, "..")) || dirread->d_name[0] != '.')
		{
			new = ft_srcs_new(dirread->d_name, dirread->d_type, path);
			ft_add_srcs(&head, &new, flags);
		}
	}
	return (head);
}
