//
// Created by youpaw on 30.03.2020.
//

#include "str_lib.h"

void print_col(void *data, int (*print)(void *), int width)
{
	int cnt;

	cnt = print(data);
	while (cnt++ < width)
		ft_putstr(" ");
}
