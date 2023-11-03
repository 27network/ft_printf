/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/03 12:48:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_type_formatter	g_formatters[] = {
['c'] = ft_format_char,
['s'] = ft_format_string,
['p'] = ft_format_pointer,
['d'] = ft_format_int,
['i'] = ft_format_int,
['u'] = ft_format_uint,
['x'] = ft_format_hex,
['X'] = ft_format_hex,
['%'] = ft_format_percent,
};

char	*ft_format_spec(t_fmt_spec *spec, va_list args)
{
	t_type_formatter	formatter;

	if (!ft_strchr(PF_SPECIFIERS, spec->specifier))
		return (NULL);
	formatter = g_formatters[(int)spec->specifier];
	if (formatter)
		return (formatter(spec, args));
	return (ft_strdup(spec->raw));
}
