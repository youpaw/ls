//
// Created by youpaw on 12.03.2020.
//

#include "ls.h"
#include "srcs.h"

int 	cmp_srcs(t_src  *src1, t_src *src2, t_flags *flags)
{
	long ret;

	if (flags->sort == f_unset)
		return (-1);
	ret = 0;
	if (flags->sort == f_mtime)
		ret = src2->info.st_mtimespec.tv_sec - src1->info.st_mtimespec.tv_sec;
	else if (flags->sort == f_ctime)
		ret = src2->info.st_ctimespec.tv_sec - src1->info.st_ctimespec.tv_sec;
	else if (flags->sort == f_atime)
		ret = src2->info.st_atimespec.tv_sec - src1->info.st_atimespec.tv_sec;
	else if (flags->sort == f_size)
		ret = src2->info.st_size - src1->info.st_size;
	if (ret == 0)
		ret = ls_strcmp(src1->name, src2->name);
	if (flags->all[31])
		ret *= -1;
	return ((int)ret);
}