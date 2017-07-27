/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 00:30:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/23 23:44:19 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft.h"
# include <dirent.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>

# define USAGE "usage: ./ft_ls [-ARSTacfglnoprstu1]\n"
# define SIXMO 15778463

typedef struct		s_file
{
	char			*name;
	char			*mode;
	unsigned int	nlink;
	char			*owner;
	char			*group;
	int				size;
	time_t			time;
	long			ntime;
	char			*link;
	int				blocks;
	struct s_file	*left;
	struct s_file	*right;
}					t_file;

typedef struct		s_err
{
	char			*path;
	char			*er_msg;
	struct s_err	*left;
	struct s_err	*right;
}					t_err;

typedef struct		s_options
{
	char			big_a;
	char			a;
	char			c;
	char			f;
	char			g;
	char			l;
	char			n;
	char			o;
	char			p;
	char			big_r;
	char			r;
	char			big_s;
	char			s;
	char			big_t;
	char			t;
	char			u;

	char			nl;
	char			folder;
	char			total;
}					t_options;

void				print_tree(t_file *file, t_options *options,
									char *path, unsigned int blocks);
void				insert_elem(t_file **tree_top, t_file *new_leaf,
									t_options *options);
char				*check_permissions(mode_t mode);
int					mark_options(int ac, char **av, t_options *options, int i);
void				build_tree(char *path, t_options *options);
size_t				get_attributes(t_file *file, char *path,
									t_options *options);
size_t				get_dirattributes(t_file *file, t_options *options);
void				list_recursive(char *path, t_file *root,
									t_options *options);
t_file				*param_tree(t_file *root, char *path, t_options *options);
void				destroy_tree(t_file *root);
t_err				*err_tree(t_err *root, char *path, char *er_msg,
									t_options *options);
void				print_err(t_err *root);
void				destroy_three_trees(t_err *err, t_file *ndir, t_file *dir);

#endif
