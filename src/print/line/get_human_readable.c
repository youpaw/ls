//
// Created by slavanya on 10.04.2020.
//

#include <libft.h>
#include <print.h>

static void 	get_itoa(char *data, size_t size)
{
	int len;

	len = ft_numlen(size);
	while (len--)
	{
		data[len] = size % 10 + '0';
		size /= 10;
	}
}

static char 	get_typesize(int type)
{
	if (type == 0)
		return ('B');
	else if (type == 1)
		return ('K');
	else if (type == 2)
		return ('M');
	else if (type == 3)
		return ('G');
	else if (type == 4)
		return ('T');
	return (' ');
}

void	get_human_readable(char data[5], size_t size)
{
	int		type;
	int		rest;

	type = 0;
	while (size >= 1000)
	{
		rest = (size / 100) % 10;
		size /= 1000;
		type++;
	}
	if (size < 10 && type)
	{
		ft_bzero(data, 5);
		data[0] = size + '0';
		data[1] = ',';
		data[2] = rest + '0';
		data[3] = get_typesize(type);
	}
	else
		get_itoa(data, size);
}