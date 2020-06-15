//
// Created by slavanya on 29.03.2020.
//

#include <print_line.h>
#include <libft.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

static void		struct_bezero(t_max_values *max)
{
	max->links = 0;
	max->uid = 0;
	max->gid = 0;
	max->size = 0;
	max->major = 0;
	max->minor = 0;
	max->total = 0;
}

static void 	get_max_len(struct stat info, t_max_values *max)
{
	int uid_len;
	int gid_len;
	int new_size_len;

	new_size_len = 0;
	uid_len = ft_strlen(getpwuid(info.st_uid)->pw_name);
	gid_len = ft_strlen(getgrgid(info.st_gid)->gr_name);
	max->uid = ft_max(gid_len, max->uid);
	max->gid = ft_max(gid_len, max->gid);
	max->size = ft_max(ft_numlen(info.st_size), max->size);
	if (S_ISBLK(info.st_mode) || S_ISCHR(info.st_mode))
	{
		max->major = ft_max(ft_numlen(major(info.st_rdev)), max->major);
		max->minor = ft_max(ft_numlen(minor(info.st_rdev)), max->minor);
		new_size_len = max->major + 1 + max->minor;
	}
	max->size = ft_max(new_size_len, max->size);
	max->links = ft_max(ft_numlen(info.st_nlink), max->links);
	max->total += info.st_size;
}

static void		get_elements(t_avl *srcs, t_max_values *max)
{
	struct stat tmp;

	if (!srcs)
		return ;
	get_elements(srcs->left, max);
	tmp = ((t_src*)srcs->content)->info;
	get_max_len(tmp, max);
	get_elements(srcs->right, max);

}

void 	get_max_values(t_avl *srcs, t_max_values *max)
{
	struct_bezero(max);
	get_elements(srcs, max);
}