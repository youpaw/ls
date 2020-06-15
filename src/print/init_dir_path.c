//
// Created by youpaw on 01.04.2020.
//

#include "str_lib.h"

void init_dir_path(char *dir_path, char *path)
{
	int len;

	len = ft_strlen(path);
	ft_strcpy(dir_path, path);
	if (dir_path[len - 1] != '/')
	{
		dir_path[len++] = '/';
		dir_path[len] = '\0';
	}
}