/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:12:40 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/03 21:45:58 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <limits.h>
# include <dirent.h>
# include <errno.h>
# define FLAGS "-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1"
# define N_FLAGS 38

typedef struct		s_srcs
{
	char			*path;
	char			*name;
	time_t			time_mod;
	int				type_file;
	struct s_srcs	*next;
}					t_srcs;

typedef struct		s_nodes
{
	char			*path;
	char			*error;
	time_t			time_mod;
	struct s_srcs	*content;
	struct s_nodes	*next;
}					t_nodes;

void				ft_get_flags(int *argc, char ***argv, char *flags);

void				ft_del_srcs(t_srcs **l);
t_srcs				*ft_srcs_new(char *name, int type, char *path);
t_srcs				*ft_srcs_list(DIR *dirp, char *path, const char *flags);
void				ft_add_srcs(t_srcs **head, t_srcs **new, const char *flags);

void				ft_add_node(t_nodes **head, t_nodes *new, \
		const char *flags);
t_nodes				*ft_new_node(char *argv, const char *flags);
void				ft_get_node(t_nodes **head, char *argv, char *flags);
void				ft_del_node(t_nodes **nodes);

t_nodes				*ft_handle_error(int code, char *argv);
t_nodes				*ft_init_error(char *name, char *path, char *error);

void				ft_all_print(const char *flag, t_nodes **major_list);
int					ft_know_max(t_srcs *content, long int *ar);
int					ft_print_l_or_not(const char *flag, t_srcs *content, \
		long int *ar);

int					ft_print_simlink(struct stat buff, t_srcs *content);
void				ft_print_filetype(struct stat buff);
void				ft_print_time(struct stat buff);
void				ft_print_acl(char *name);
void				ft_print_rights(mode_t mode);
void				ft_print_major_minor(struct stat buff);
void				ft_print_nlink(struct stat buff, int i);
void				ft_print_name_group(const char *flag, struct stat buff, \
		int n, int g);
void				ft_print_size(const char *flag, struct stat buff, int i);
int					ft_print_filename(const char *flag, t_srcs *content);
int					ft_print_flag_i(const char *flag, struct stat buff);
#endif
