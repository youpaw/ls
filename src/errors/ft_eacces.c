/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eacces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:46:03 by bford             #+#    #+#             */
/*   Updated: 2019/10/30 23:40:18 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errors.h"

t_nodes		*ft_eacces(char *argv)
{
	char	*s;

	if ((s = ft_strrchr(argv, '/')))
		s++;
	else
		s = argv;
	return (ft_init_error(s, argv, ": Permission denied\n"));
}
