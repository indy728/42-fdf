/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:48:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/24 00:56:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static char	check_type(mode_t mode)
{
	char	isdir;

	isdir = '-';
	if (S_ISDIR(mode))
		isdir = 'd';
	else if (S_ISREG(mode))
		isdir = '-';
	else if (S_ISLNK(mode))
		isdir = 'l';
	else if (S_ISBLK(mode))
		isdir = 'b';
	else if (S_ISCHR(mode))
		isdir = 'c';
	else if (S_ISSOCK(mode))
		isdir = 's';
	else if (S_ISFIFO(mode))
		isdir = 'p';
	return (isdir);
}

static void	check_idsticky(char *permissions, mode_t mode)
{
	if (S_ISUID & mode)
		permissions[3] = permissions[3] == 'x' ? 's' : 'S';
	if (S_ISGID & mode)
		permissions[6] = permissions[6] == 'x' ? 's' : 'S';
	if (S_ISVTX & mode)
		permissions[9] = permissions[9] == 'x' ? 't' : 'T';
}

char		*check_permissions(mode_t mode)
{
	char	*permissions;

	permissions = ft_strnew(10);
	permissions = ft_memset(permissions, '-', 10);
	permissions[0] = check_type(mode);
	if (S_IRUSR & mode)
		permissions[1] = 'r';
	if (S_IWUSR & mode)
		permissions[2] = 'w';
	if (S_IXUSR & mode)
		permissions[3] = 'x';
	if (S_IRGRP & mode)
		permissions[4] = 'r';
	if (S_IWGRP & mode)
		permissions[5] = 'w';
	if (S_IXGRP & mode)
		permissions[6] = 'x';
	if (S_IROTH & mode)
		permissions[7] = 'r';
	if (S_IWOTH & mode)
		permissions[8] = 'w';
	if (S_IXOTH & mode)
		permissions[9] = 'x';
	check_idsticky(permissions, mode);
	return (permissions);
}
