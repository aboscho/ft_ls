/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:32:52 by abosch            #+#    #+#             */
/*   Updated: 2020/02/06 18:28:58 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list	**sort(t_list *files, int16_t opt)
{
	if (opt & O_REVERSE)
	{
		if (opt & O_TIME)
			return (ft_lstquicksorttab(files, &rtime_cmp));
		else
			return (ft_lstquicksorttab(files, &rname_cmp));
	}
	else
	{
		if (opt & O_TIME)
			return (ft_lstquicksorttab(files, &time_cmp));
		else
			return (ft_lstquicksorttab(files, &name_cmp));
	}
}

static void		handle_dir(t_list *dir, t_list **tab, int16_t *opt)
{
	int		i;
	t_dir	*tmp;

	if (!(*opt & O_RECUR))
		return ;
	*opt |= O_HEADER;
	i = -1;
	while (tab[++i] != NULL)
		if (S_ISDIR(((t_file*)tab[i]->content)->sbuf.st_mode))
		{
			make_dir(((t_file*)tab[i]->content)->name, ((t_file*)tab[i]->content)->path_len, ((t_file*)tab[i]->content)->name_len, &tmp);
			ft_lstinsert(dir, ft_lstnew(tmp, sizeof(t_dir)));
			dir = dir->next;
		}
}

void			list_files(char *path, int pathlen, int16_t *opt, t_list *dir)
{
	DIR				*dirp;
	struct dirent	*ret;
	t_list			*files;
	t_list			**tab_files;

	files = NULL;
	if (path[pathlen - 1] != '/')
		path[pathlen] = '/';
	if (!(dirp = opendir(path)))
	{
		ft_printerr("ft_ls: %.*s: %s\n", ft_strlen(path) - 1, path, strerror(errno));
		exit(1);
	}
	while ((ret = readdir(dirp)))
		create_file(path, ret->d_name, &files, *opt);
	tab_files = sort(files, *opt);
	handle_dir(dir, tab_files, opt);
	if (*opt & O_LFORMAT)
		print_files(tab_files, 0, 1);
	else
		print_files(tab_files, 1, 1);
	if(closedir(dirp) == -1)
		ft_printerr("close dir didn't work with %p\n", dirp);
}

static void		print_inputf(t_list *files, t_list *dir, int16_t opt)
{
	t_list	**tab;

	if (files == NULL)
		return ;
	tab = sort(files, opt);
	if (opt & O_LFORMAT)
		print_files(tab, 0, 0);
	else
		print_files(tab, 1, 0);
	if (dir != NULL)
		ft_printf("\n");
}

void			ft_ls(char **av, int ac)
{
	int		len;
	int16_t	options;
	t_list	*dir;
	t_list	*input;

	options = 0;
	dir = NULL;
	input = NULL;
	options |= O_ONEFILE;
	get_options(ac, av, &options, &input);
	options &= ~O_ONEFILE;
	move_dir(&input, &dir);
	print_inputf(input, dir, options);
	ft_lstquicksort(&dir, &dname_cmp);
	len = ft_lstlen(dir);
	while (dir != NULL)
	{
		if (len > 1 || options & O_HEADER)
			ft_printf("%s:\n", D(dir)->name);
		list_files(D(dir)->name, D(dir)->name_len + D(dir)->path_len, &options, dir);
		if (dir->next != NULL)
			ft_printf("\n");
		dir = dir->next;
	}
}
