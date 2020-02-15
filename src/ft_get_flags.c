/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:12:24 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 21:48:47 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_einval(char *name, char option)
{
	if (!option)
		return ;
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd("\nusage: ls [", 2);
	ft_putstr_fd(FLAGS, 2);
	ft_putstr_fd("] [file ...]\n", 2);
	exit(1);
}

static int			ft_check_collision(char *flags, unsigned short index)
{
	if (flags[0])
		return (1);
	if (index == 37)
	{
		flags[21] = 0;
		flags[25] = 0;
		flags[27] = 0;
		flags[28] = 0;
		flags[29] = 0;
	}
	return (0);
}

void				ft_get_flags(int *argc, char ***argv, char *flags)
{
	char			*name;
	unsigned short	k;

	name = *(*argv)++;
	ft_bzero(flags, N_FLAGS);
	while (--(*argc) && ***argv == '-' && *(**argv + 1) && !flags[0])
	{
		k = 0;
		(**argv)++;
		while (k < N_FLAGS && ***argv)
			if (***argv == FLAGS[k])
			{
				(**argv)++;
				if (ft_check_collision(flags, k))
					ft_einval(name, '-');
				flags[k] = 1;
				k = 0;
			}
			else
				k++;
		ft_einval(name, ***argv);
		(*argv)++;
	}
}
