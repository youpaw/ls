/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:15:08 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 20:25:24 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_print_filename(const char *flag, t_srcs *content)
{
	ft_putstr(content->name);
	if (flag[29] && content->type_file == 4)
		ft_putchar('/');
	return (1);
}
