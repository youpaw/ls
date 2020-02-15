/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_acl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:28:48 by bford             #+#    #+#             */
/*   Updated: 2019/11/01 17:29:40 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/acl.h>
#include <sys/xattr.h>

void	ft_print_acl(char *name)
{
	acl_t			acl;
	acl_entry_t		dummy;
	ssize_t			xattr;

	acl = acl_get_link_np(name, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		ft_putchar('@');
	else if (acl != NULL)
		ft_putchar('+');
	else
		ft_putchar(' ');
	ft_putchar(' ');
}
