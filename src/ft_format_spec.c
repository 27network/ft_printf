/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/04 23:43:08 by kiroussa         ###   ########.fr       */
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

static char	*ft_apply_formatters(t_fmt_spec *spec, va_list args)
{
	t_type_formatter	formatter;

	if (ft_strchr(PF_SPECIFIERS, spec->specifier))
	{
		formatter = g_formatters[(int)spec->specifier];
		if (formatter)
			return (formatter(spec, args));
	}
	return (NULL);
}

static char	*ft_pad(char *str, int n, char c, int left)
{
	char	*pad;
	char	*tmp;

	if (n <= (int)ft_strlen(str))
		return (str);
	n -= ft_strlen(str);
	if (n < 0)
		return (str);
	pad = ft_calloc(n + 1, sizeof(char));
	if (!pad)
		return (NULL);
	ft_memset(pad, c, n);
	if (left)
		tmp = ft_strjoin(str, pad);
	else
		tmp = ft_strjoin(pad, str);
	free(pad);
	free(str);
	return (tmp);
}

char	*ft_format_spec(t_fmt_spec *spec, va_list args)
{
	char	*formatted;

	formatted = ft_apply_formatters(spec, args);
	if (formatted)
	{
		if (spec->specifier == 'c' && formatted[0] == '\0')
			spec->width--;
		if (spec->width > 0)
			formatted = ft_pad(formatted, spec->width, ' ',
					spec->flags & PF_LEFT_JUSTIFY);
		if (formatted)
			return (formatted);
	}
	return (ft_strdup(spec->raw));
}
