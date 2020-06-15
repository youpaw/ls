//
// Created by slavanya on 21.03.2020.
//

#include <print.h>
#include <print_line.h>
#include <grp.h>
#include <pwd.h>
#include "srcs.h"

/*
 * 37 - is -1 flag
 */

static void get_call(t_src *src, char *path, t_max_values max, t_flags *flags)
{
	if (flags->all[37])
	{
		print_name_endl(src->name, src->info.st_mode);
		return ;
	}
	print_mode(src->name, src->info.st_mode);
	print_nlink(src->info.st_nlink, max.links);
	if (!flags->all[21])
		print_uid(getpwuid((src->info).st_uid)->pw_name, max.uid);
	if (!flags->all[28])
		print_gid(getgrgid((src->info).st_gid)->gr_name, max.uid);
	print_size(src->info, max, flags);
	print_date(src->info, flags);
	S_ISLNK(src->info.st_mode) ? print_link(path, src) : \
	print_name_endl(src->name, src->info.st_mode);
}

static void	get_elements(t_avl *srcs, char *path, t_max_values max, t_flags *flags)
{
	static t_src *tmp;

	if (!srcs)
		return ;
	get_elements(srcs->left, path, max, flags);
	tmp = (t_src *) srcs->content;
	get_call(tmp, path, max, flags);
	get_elements(srcs->right, path, max, flags);
}

void print_srcs_line(t_avl *srcs, char *path, t_flags *flags)
{
	t_max_values max;

	get_max_values(srcs, &max);
	print_total(flags, max.total);
	get_elements(srcs, path, max, flags);
}
