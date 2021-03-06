/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:52:18 by abosch            #+#    #+#             */
/*   Updated: 2020/02/20 12:52:24 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "internal/integers.h"
#include "internal/output.h"
#include "internal/percent.h"
#include "internal/type_utils.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void	type_o(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	char		str[24];
	char		prefix[2];
	size_t		nbr;

	nbr = get_cast_arg_unsigned(ap, spec->size);
	conv.str = ft_lluitosa_base(nbr, 8, str);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_BLANK);
	if (spec->flags & F_PRECI)
		spec->flags &= ~F_ZERO;
	if (spec->flags & F_PRECI && nbr == 0 && !(spec->flags & F_HASH))
		conv.len = 0;
	if (conv.len + 1 > spec->precision && spec->flags & F_HASH && nbr != 0)
	{
		spec->prefix = ft_strcpy(prefix, "0");
		spec->prefix_len = 1;
	}
	else
		spec->flags &= ~F_HASH;
	write_percent(spec, &conv, buf);
}

void	type_x(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	char		str[17];
	char		prefix[3];
	size_t		nbr;

	nbr = get_cast_arg_unsigned(ap, spec->size);
	conv.str = ft_lluitosa_base(nbr, 16, str);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_BLANK);
	if (spec->flags & F_PRECI)
		spec->flags &= ~F_ZERO;
	if (spec->flags & F_PRECI && nbr == 0)
		conv.len = 0;
	if (spec->flags & F_HASH && nbr != 0)
	{
		spec->prefix = ft_strcpy(prefix, "0x");
		spec->prefix_len = 2;
	}
	else
		spec->flags &= ~F_HASH;
	write_percent(spec, &conv, buf);
}

void	type_xx(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	char		str[17];
	char		prefix[3];
	size_t		nbr;

	nbr = get_cast_arg_unsigned(ap, spec->size);
	conv.str = ft_lluitosa_base(nbr, 16, str);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_BLANK);
	if (spec->flags & F_PRECI)
		spec->flags &= ~F_ZERO;
	if (spec->flags & F_PRECI && nbr == 0)
		conv.len = 0;
	if (spec->flags & F_HASH && nbr != 0)
	{
		spec->prefix = ft_strcpy(prefix, "0X");
		spec->prefix_len = 2;
	}
	else
		spec->flags &= ~F_HASH;
	nbr = -1;
	while (conv.str[++nbr] != '\0')
		if (conv.str[nbr] >= 'a' && conv.str[nbr] <= 'f')
			conv.str[nbr] -= 32;
	write_percent(spec, &conv, buf);
}

void	type_b(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	char		prefix[2];
	char		str[64];
	size_t		nbr;

	nbr = get_cast_arg_unsigned(ap, spec->size);
	conv.str = ft_lluitosa_base(nbr, 2, str);
	if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ' ', 4);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_BLANK);
	if (spec->flags & F_HASH)
	{
		spec->prefix = ft_strcpy(prefix, "b");
		spec->prefix_len = 2;
	}
	write_percent(spec, &conv, buf);
	if (spec->flags & F_QUOTE)
		free(conv.str);
}

void	type_bb(va_list ap, t_spec *spec, t_buf *buf)
{
	t_string	conv;
	size_t		nbr;
	int8_t		base;

	nbr = get_cast_arg_unsigned(ap, spec->size);
	base = va_arg(ap, int);
	conv.str = ft_lluitoa_base(nbr, base);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_BLANK | F_HASH);
	write_percent(spec, &conv, buf);
}
