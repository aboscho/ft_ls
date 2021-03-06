/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:44:09 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:46:17 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <grp.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <pwd.h>

# include "shared.h"
# include "libft.h"
# include "file.h"
# include "destroy.h"

typedef struct	s_max
{
	size_t		nlink;
	size_t		user;
	size_t		group;
	long long	size;
	size_t		sum;
}				t_max;

void			print_files(t_list **tab, char dir, int16_t opt);
void			long_print(t_file *file, t_max max);

#endif
