//
// Created by youpaw on 11.03.2020.
//

#include "flags.h"
#include "mem_lib.h"

t_flags *init_flags(void)
{
	t_flags *flags;

	flags = (t_flags*)ft_xmalloc(sizeof(t_flags));
	ft_bzero(flags->all, N_FLAGS);
	flags->sort = f_ascii;
	flags->print = f_col;
	flags->display = f_mtime;
	return (flags);
}
