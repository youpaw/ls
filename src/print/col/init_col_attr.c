//
// Created by youpaw on 26.03.2020.
//

#include "print_col.h"
#include "mem_lib.h"
#include <sys/ioctl.h>
#include <zconf.h>

static void get_srcs_params(t_avl *srcs, t_srcs_params *params)
{
	static t_src *src;

	if (!srcs)
		return ;
	src = (t_src*)srcs->content;
	if (src->len > (params->max_name + N_COL_PAD))
		params->max_name = src->len + N_COL_PAD;
	params->sum_name += src->len + N_COL_PAD;
	get_srcs_params(srcs->left, params);
	get_srcs_params(srcs->right, params);
}

static void get_col_widths(t_avl *srcs, t_print_col *attr)
{
	static t_src *src;

	if (!srcs)
		return ;
	get_col_widths(srcs->left, attr);
	src = (t_src*)srcs->content;
	if ((src->len + N_COL_PAD) > attr->widths[attr->id])
		attr->widths[attr->id] = src->len + N_COL_PAD;
	attr->id = (attr->id + 1) % attr->n;
	get_col_widths(srcs->right, attr);
}

static void init_srcs_params(t_srcs_params *params)
{
	params->max_name = 0;
	params->sum_name = 0;
}

void init_col_attr(t_avl *srcs, t_print_col *attr)
{
	t_srcs_params params;
	struct winsize w;

	init_srcs_params(&params);
	get_srcs_params(srcs, &params);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	attr->widths = NULL;
	attr->id = 0;
	if (params.sum_name <= w.ws_col)
		attr->n = 0;
	else if ((attr->n = w.ws_col / params.max_name) < 2)
		attr->n = 1;
	else
	{
		attr->widths = (int*)ft_xmalloc(sizeof(int) * attr->n);
		ft_bzero(attr->widths, sizeof(int) * attr->n);
		get_col_widths(srcs, attr);
		attr->id = 0;
	}
}
