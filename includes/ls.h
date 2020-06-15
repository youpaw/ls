//
// Created by youpaw on 12.03.2020.
//

#ifndef LS_H
#define LS_H
#include "flags.h"
#include "list_lib.h"

void	print_args(t_list *nodes, t_flags *flags);

t_list *parse_args(int argc, char **argv, int skip, t_flags *flags);

int		ls_strcmp(const char *s1, const char *s2);

#endif //LS_H
