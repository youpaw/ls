//
// Created by youpaw on 01.04.2020.
//

#include "str_lib.h"
#include "mem_lib.h"
#include "print.h"
#include <zconf.h>

static int get_link_path(char *path, char *name, char *buf)
{
	int ret;
	struct stat info;

	ft_bzero(buf, MAX_PATHLEN);
	ft_strcat(path, name);
	readlink(path, buf, MAX_PATHLEN);
	ret = stat(path, &info) ? -1 : info.st_mode;
	path[ft_strlen(path) - ft_strlen(name)] = '\0';
	return (ret);
}

void	print_link(char *path, t_src *src)
{
	char buf[MAX_PATHLEN];
	int	mode;

	mode = get_link_path(path, src->name, buf);
	mode < 0 ? print_name(src->name, -1) : print_name(src->name, src->info.st_mode);
	ft_putstr(" -> ");
	print_name_endl(buf, mode);
}
