/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 11:55:52 by bford             #+#    #+#             */
/*   Updated: 2019/11/02 12:00:20 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putunsnbr(unsigned long long n)
{
	if (n > 9)
		ft_putunsnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void		ft_putnbr_ll(long long n)
{
	unsigned long long t;

	if (n < 0)
	{
		ft_putchar('-');
		t = (unsigned long long)(~n + 1);
	}
	else
		t = (unsigned long long)n;
	ft_putunsnbr(t);
}
