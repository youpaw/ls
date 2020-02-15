/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:41:51 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 21:43:06 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H
# include "ft_ls.h"
# define ERRNUM 4

typedef struct			s_errors
{
	int					code;
	t_nodes				*(*f)(char *argv);
}						t_errors;

t_nodes					*ft_enoent(char *argv);

t_nodes					*ft_eacces(char *argv);

t_nodes					*ft_enotdir(char *argv);

static const t_errors	g_errors[ERRNUM] =
{
	{2, &ft_enoent},
	{13, &ft_eacces},
	{20, &ft_enotdir}
};

#endif
