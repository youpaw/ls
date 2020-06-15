//
// Created by youpaw on 16.03.2020.
//

#ifndef SRCS_H
#define SRCS_H

#include <sys/stat.h>
#include <dirent.h>
#include "search_lib.h"
#include "flags.h"
#define MAX_FILENAME 256
#define MAX_PATHLEN 256

struct s_src
{
	char		name[MAX_FILENAME];
	int 		len;
	struct stat	info;
};

typedef struct s_src t_src;

t_src	*init_src(char name[MAX_FILENAME], struct stat info);
t_avl	*get_srcs(DIR *dir, char *argv, t_flags *flags); // Уже написанно
void	del_src(t_src **src);
int 	cmp_srcs(t_src  *src1, t_src *src2, t_flags *flags); //Почти как cmp_nodes

#endif //SRCS_H
