/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavanya <slavanya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:30:22 by slavanya          #+#    #+#             */
/*   Updated: 2020/03/30 20:17:28 by slavanya         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int parse_flags(t_flags *flags, int argc, char **argv)
{
	int cnt;
	char *flags_str;

	cnt = 1;
	while (cnt < argc && *argv[cnt] == '-' && *(argv[cnt] + 1))
	{
		flags_str = argv[cnt] + 1;
		if (*flags_str == '-' && !*(flags_str + 1))
		{
			cnt++;
			break ;
		}
		while (*flags_str)
		{
			if (get_flag(flags, *flags_str))
				flags_error(*flags_str);
			flags_str++;
		}
		cnt++;
	}
	return (cnt);
}
