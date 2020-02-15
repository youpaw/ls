/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:00:54 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 21:48:14 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nodes		*ft_init_error(char *name, char *path, char *error)
{
	char	*s;
	t_nodes	*new;

	if (!(new = (t_nodes *)malloc(sizeof(t_nodes))))
		exit(12);
	if (!(new->path = ft_strdup(path)))
		exit(12);
	if (!(new->error = ft_strdup("ls: ")))
		exit(12);
	if (name && !*name)
		name = "fts_open";
	if (!(s = ft_strjoin(new->error, name)))
		exit(12);
	free(new->error);
	if (!(new->error = ft_strjoin(s, error)))
		exit(12);
	free(s);
	new->time_mod = 0;
	new->content = NULL;
	new->next = NULL;
	errno = 0;
	return (new);
}
