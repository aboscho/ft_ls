/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:43:59 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:44:01 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# include <stdint.h>

# include "libft.h"
# include "file.h"

# define O_LFORMAT 1
# define O_RECUR 2
# define O_TIME 4
# define O_REVERSE 16
# define O_ALL 32
# define O_ONE 64
# define O_ONEFILE 128
# define O_HEADER 256

void	get_input(int ac, char **av, int16_t *opt, t_list **dir);

#endif
