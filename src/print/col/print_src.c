//
// Created by youpaw on 27.03.2020.
//
#include "print_col.h"
#include "str_lib.h"
#include "print.h"

static int	get_mode(t_src *src, char *path)
{
	int		ret;
	struct stat info;

	if (!S_ISLNK(src->info.st_mode))
		return (src->info.st_mode);
	ft_strcat(path, src->name);
	ret = stat(path, &info) ? -1 : info.st_mode;
	path[ft_strlen(path) - ft_strlen(src->name)] = '\0';
	return (ret);
}

void print_src(t_src *src, char *path, t_print_col *attr)
{
	int cnt;
	int mode;

	mode = get_mode(src, path);
	if (!attr->n)
	{
		print_name(src->name, mode);
		cnt = 0;
		while (cnt++ < N_COL_PAD)
			ft_putstr(COL_PAD);
	}
	else if (attr->n == 1)
		print_name_endl(src->name, mode);
	else
	{
		print_name(src->name, mode);
		cnt = attr->widths[attr->id] - src->len;
		while (cnt--)
			ft_putstr(COL_PAD);
		if (attr->id == attr->n - 1)
			ft_putstr("\n");
		attr->id = (attr->id + 1) % attr->n;
	}
}
