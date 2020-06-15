//
// Created by youpaw on 16.03.2020.
//

#include "srcs.h"
#include "mem_lib.h"
#include "str_lib.h"

t_src	*init_src(char name[MAX_FILENAME], struct stat info)
{
		t_src *new_src;

		new_src = ft_xmalloc(sizeof(t_src));
		new_src->info = info;
		ft_strcpy(new_src->name, name);
		new_src->len = ft_strlen(name);
		return(new_src);
}