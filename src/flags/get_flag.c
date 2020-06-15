//
// Created by slavanya on 21.03.2020.
//

#include "flags.h"

static void		apply_f_flag(t_flags *flags)
{
	int cnt;

	cnt = 0;
	while (cnt < N_SORT_FLAGS)
		flags->all[g_map_sort[cnt++].index] = 0;
	cnt = 0;
	while (cnt < N_PRINT_FLAGS)
		flags->all[g_map_print[cnt++].index] = 0;
	flags->all[13] = 1;
	flags->all[15] = 1;
	flags->print = f_col;
	flags->sort = f_unset;
}

static int	set_sort_flag(t_flags *flags, char c)
{
	int cnt;

	cnt = 0;
	while (cnt < N_SORT_FLAGS && g_map_sort[cnt].c != c)
		cnt++;
	if (cnt < N_SORT_FLAGS)
	{
		if (c == 'c' || c == 'u')
		{
			if (flags->all[25] && flags->all[33])
			{
				flags->sort = g_map_sort[cnt].map;
				flags->display = g_map_sort[cnt].map;
			}
			else if (!flags->all[25])
				flags->sort = g_map_sort[cnt].map;
		}
		else if (c == 'f')
			apply_f_flag(flags);
		else
			flags->sort = g_map_sort[cnt].map;
		return (0);
	}
	return (1);
}

static int	set_print_flag(t_flags *flags, char c)
{
	int cnt;

	cnt = 0;
	while (cnt < N_PRINT_FLAGS && g_map_print[cnt].c != c)
		cnt++;
	if (cnt < N_PRINT_FLAGS)
	{
		flags->print = g_map_print[cnt].map;
		return (0);
	}
	return (1);
}

int	get_flag(t_flags *flags, char c)
{
	int cnt;

	cnt = 1;
	while (cnt < N_FLAGS && FLAGS[cnt] != c)
		cnt++;
	if (cnt < N_FLAGS)
	{
		if (set_print_flag(flags, c))
			set_sort_flag(flags, c);
		(flags->all)[cnt] = FLAGS[cnt];
		return (0);
	}
	return (1);
}