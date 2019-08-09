/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:31:03 by abosch            #+#    #+#             */
/*   Updated: 2018/11/15 16:59:16 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/tmp.h"

void	ft_striter(char *s, void (*f)(char*))
{
	if (s && f)
		while (*s)
			f(s++);
}
