/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:54:48 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 21:48:00 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errors.h"

t_nodes	*ft_handle_error(int code, char *argv)
{
	int i;

	i = 0;
	while (i < ERRNUM)
	{
		if (code == g_errors[i].code)
		{
			errno = code;
			return (g_errors[i].f(argv));
		}
		i++;
	}
	exit(code);
}
