/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:24:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 06:03:31 by kiroussa         ###   ########.fr       */
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

static char	*ft_apply_flag_mutators(t_fmt_spec *spec, char *str)
{
	if (spec->specifier == 's')
		str = ft_precision_mutator_str(spec, str);
	else if (ft_strchr("diuxX", spec->specifier))
		str = ft_precision_mutator_int(spec, str);
	if (spec->flags & PF_LEFT_JUSTIFY)
		str = ft_leftjustify_mutator(spec, str);
	if (!(spec->flags & PF_LEFT_JUSTIFY))
		str = ft_padding_mutator(spec, str);
	str = ft_hash_mutator_prefix(spec, str);
	return (str);
}

static char	*ft_apply_formatters(t_fmt_spec *spec, va_list args, int *hnc)
{
	t_type_formatter	formatter;
	char				*result;

	result = NULL;
	*hnc = 0;
	if (ft_strchr(PF_SPECIFIERS, spec->specifier))
	{
		formatter = g_formatters[(int)spec->specifier];
		if (formatter)
			result = formatter(spec, args);
		if (result && spec->specifier == 'c' && *result == '\0')
		{
			*hnc = 1;
			free(result);
			result = ft_strdup("a");
		}
	}
	return (result);
}

char	*ft_format_spec(t_fmt_spec *spec, va_list args, int *len)
{
	char	*formatted;
	int		has_null_char;

	*len = 0;
	formatted = ft_apply_formatters(spec, args, &has_null_char);
	if (formatted)
	{
		if (formatted && spec->specifier != '%')
			formatted = ft_apply_flag_mutators(spec, formatted);
		if (formatted)
			*len = ft_strlen(formatted);
		if (has_null_char)
			ft_strchr(formatted, 'a')[0] = '\0';
	}
	if (!formatted)
	{
		formatted = ft_strdup(spec->raw);
		if (formatted)
			*len = ft_strlen(formatted);
	}
	return (formatted);
}
