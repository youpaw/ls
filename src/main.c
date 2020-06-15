/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavanya <slavanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:00:11 by slavanya          #+#    #+#             */
/*   Updated: 2020/03/30 14:20:11 by slavanya         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "ls.h"

int     main(int argc, char **argv)
{
	int		skip;
	t_flags	*flags;
	t_list	*nodes;

	flags = init_flags();
    skip = parse_flags(flags, argc, argv);
    nodes = parse_args(argc, argv, skip, flags);
    print_args(nodes, flags);
	ft_lstdelone(&nodes, (void (*)(void *)) &del_node);
    del_flags(&flags);
    return (0);
}
