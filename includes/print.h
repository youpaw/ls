//
// Created by youpaw on 16.03.2020.
//

#ifndef PRINT_H
#define PRINT_H
#include "nodes.h"
# define N_ERRORS 2
# define COL_IFO	"\033[40;33m"
# define COL_CHR	"\033[1;40;33m"
# define COL_DIR	"\033[1;34m"
# define COL_BLK	"\033[1;40;35m"
# define COL_REG	"\033[0m"
# define COL_LNK	"\033[1;36m"
# define COL_SOCK	"\033[1;35m"
# define COL_EXE	"\033[1;32m"
# define COL_ERR	"\033[1;40;31m"
# define COL_CLR	"\033[0m"

struct s_print{
	int need_head;
	int need_space;
};

struct s_errors{
	int		code;
	char	*str;
};

typedef struct s_print	t_print;

static struct s_errors g_errors[N_ERRORS] = {
		{2, "cannot access"},
		{13, "cannot open directory"}
};

void init_dir_path(char *dir_path, char *path);
void	print_col(void *data, int (*print)(void *), int width);
void	print_col_right(void *data, int (*print)(void *), int (*len)(void *), int width);
void 	print_name(char *name, int mode);
void 	print_name_endl(char *name, int mode);
void print_srcs(t_avl *srcs, char *path, t_flags *flags);
void	print_node(t_node *node, t_flags *flags, t_print *attr);
void	print_dir_node(t_node *node, t_flags *flags, t_print *attr);
void	print_file_node(t_node *node, t_flags *flags, t_print *attr);
void	print_error(char *path);

#endif //PRINT_H
