//
// Created by youpaw on 30.03.2020.
//

#include "str_lib.h"

void print_col_right(void *data, int (*print)(void *), int (*len)(void *), \
	int width)
{
	int cnt;

	cnt = width - len(data);
	while (cnt-- > 0)
		ft_putstr(" ");
	print(data);
}