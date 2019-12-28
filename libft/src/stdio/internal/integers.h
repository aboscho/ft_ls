/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:01:06 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/20 18:47:19 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGERS_H
# define INTEGERS_H
# define INT_MAX 2147483647
# include "libft.h"

int		get_number(char **str);
char	*nbr_grouping(t_string *conv, char sep, unsigned int size);

/*
** INTEGERS_H
*/
#endif
