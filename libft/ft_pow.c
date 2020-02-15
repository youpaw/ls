/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:45:53 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/14 21:27:49 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_pow(unsigned int x, unsigned short n)
{
	unsigned int res;

	res = 1;
	if (n == 0)
		return (1);
	while (n--)
		res *= x;
	return (res);
}
