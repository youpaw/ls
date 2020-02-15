/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:24:36 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/28 22:25:01 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp_case(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (*ps1 && *ps2)
	{
		if (ft_tolower(*ps1) != ft_tolower(*ps2))
			break ;
		ps1++;
		ps2++;
	}
	return ((int)(ft_tolower(*ps1) - ft_tolower(*ps2)));
}
