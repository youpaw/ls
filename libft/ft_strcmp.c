/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 22:03:52 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/11 14:34:43 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	while (*ps1 && *ps2)
	{
		if (*ps1 != *ps2)
			break ;
		ps1++;
		ps2++;
	}
	return ((int)(*ps1 - *ps2));
}
