/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirattributes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:51:40 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/23 23:16:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	get_time(t_file *file, struct stat st, t_options *options)
{
	if (options->c)
	{
		file->time = st.st_ctime;
		file->ntime = st.st_ctimespec.tv_nsec;
	}
	else if (options->u)
	{
		file->time = st.st_atime;
		file->ntime = st.st_atimespec.tv_nsec;
	}
	else
	{
		file->time = st.st_mtime;
		file->ntime = st.st_mtimespec.tv_nsec;
	}
}

static void	get_id(t_file *file, t_options *options, struct stat st)
{
	struct passwd	*pass;
	struct group	*grp;

	if (!options->n && (pass = getpwuid(st.st_uid)))
		file->owner = ft_strdup(pass->pw_name);
	else
		file->owner = ft_itoa(st.st_uid);
	if (!options->n && (grp = getgrgid(st.st_gid)))
		file->group = ft_strdup(grp->gr_name);
	else
		file->group = ft_itoa(st.st_gid);
}

size_t		get_dirattributes(t_file *file, t_options *options)
{
	struct stat		st;

	if (lstat(file->name, &st) == -1)
	{
		perror("lstat error");
		exit(1);
	}
	file->mode = check_permissions(st.st_mode);
	file->nlink = (unsigned int)st.st_nlink;
	get_id(file, options, st);
	get_time(file, st, options);
	file->size = (unsigned int)st.st_size;
	return (st.st_blocks);
}
