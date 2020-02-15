/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:37 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/29 20:31:28 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	char	flags[N_FLAGS];
	t_nodes	*head;

	ft_get_flags(&argc, &argv, flags);
	head = NULL;
	if (!argc)
		ft_get_node(&head, ".", flags);
	while (argc--)
		ft_get_node(&head, *argv++, flags);
	ft_all_print(flags, &head);
	return (0);
}
