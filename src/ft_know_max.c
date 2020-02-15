/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_know_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:27:20 by bford             #+#    #+#             */
/*   Updated: 2019/11/03 21:52:52 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

static void			ft_len_for_print(long int n, int i, long int *ar)
{
	while (n > 9 && ar[i]++)
		n /= 10;
}

static void			ft_init_array(long int *ar)
{
	ar[0] = 0;
	ar[1] = 1;
	ar[2] = 1;
	ar[3] = 0;
	ar[5] = 0;
	ar[6] = 0;
}

static void			ft_len_name(size_t pw_name, long int *ar)
{
	long int		len;

	len = (long int)pw_name;
	*ar = (len > *ar ? len : *ar);
}

int					ft_know_max(t_srcs *content, long int *ar)
{
	struct stat		buff;
	t_srcs			*copy;
	long int		big_size;
	int				links;

	ft_init_array(ar);
	big_size = 0;
	links = 0;
	copy = content;
	while (copy)
	{
		ar[3] = ((long int)ft_strlen(copy->name) > ar[3] ?
		ft_strlen(copy->name) : ar[3]);
		if (lstat(copy->path, &buff))
			return (1);
		ar[0] += buff.st_blocks;
		ft_len_name(ft_strlen((getpwuid(buff.st_uid))->pw_name), &(ar[5]));
		ft_len_name(ft_strlen((getgrgid(buff.st_gid))->gr_name), &(ar[6]));
		links = (buff.st_nlink > links ? buff.st_nlink : links);
		big_size = (buff.st_size > big_size ? buff.st_size : big_size);
		copy = copy->next;
	}
	ft_len_for_print(big_size, 2, ar);
	ft_len_for_print((long int)links, 1, ar);
	return (0);
}
