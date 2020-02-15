/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nlink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:40:35 by bford             #+#    #+#             */
/*   Updated: 2019/11/01 17:40:46 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_nlink(struct stat buff, int i)
{
	while (i-- > ft_lennbr(buff.st_nlink))
		ft_putchar(' ');
	ft_putnbr(buff.st_nlink);
	ft_putchar(' ');
}
