/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enoent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:52:44 by bford             #+#    #+#             */
/*   Updated: 2019/10/30 23:42:17 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errors.h"

t_nodes	*ft_enoent(char *argv)
{
	return (ft_init_error(argv, argv, ": No such file or directory\n"));
}
