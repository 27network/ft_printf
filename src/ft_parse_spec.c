/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:47:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/04 23:22:08 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fill_flags(const char *format, t_fmt_spec *spec)
{
	int	i;

	i = 0;
	spec->flags = 0;
	while (format[i] && ft_strchr(PF_FLAGS, format[i]))
	{
		if (format[i] == PF_FLAGS[0])
			spec->flags |= PF_LEFT_JUSTIFY;
		else if (format[i] == PF_FLAGS[1])
			spec->flags |= PF_ZERO_PAD;
		else if (format[i] == PF_FLAGS[2])
			spec->flags |= PF_SPACE;
		else if (format[i] == PF_FLAGS[3])
			spec->flags |= PF_HASH;
		else if (format[i] == PF_FLAGS[4])
			spec->flags |= PF_PLUS;
		i++;
	}
	return (i);
}

static int	ft_spec_length(const char *fmt_str)
{
	int	len;
	int	precision;

	len = 0;
	while (fmt_str[len] && ft_strchr(PF_FLAGS, fmt_str[len]))
		len++;
	while (ft_isdigit(fmt_str[len]))
		len++;
	precision = fmt_str[len] == '.';
	if (precision)
		len++;
	if (precision)
		while (ft_isdigit(fmt_str[len]))
			len++;
	if (ft_strchr(PF_SPECIFIERS, fmt_str[len]))
		len++;
	else
		return (0);
	return (len);
}

static char	*ft_parse_int(char *raw, int *ptr, va_list args)
{
	if (*raw == '*')
	{
		*ptr = va_arg(args, int);
		raw++;
	}
	else
	{
		*ptr = ft_atoi(raw);
		while (ft_isdigit(*raw))
			raw++;
	}
	return (raw);
}

static void	ft_fill_spec(t_fmt_spec *spec, va_list args)
{
	char	*raw;

	raw = spec->raw + ft_fill_flags(spec->raw, spec);
	raw = ft_parse_int(raw, &spec->width, args);
	if (*raw == '.')
		raw = ft_parse_int(++raw, &spec->precision, args);
	else
		spec->precision = -1;
	spec->length = ft_substr(raw, 0, ft_strlen(raw) - 1);
	raw += ft_strlen(spec->length);
	spec->specifier = *raw;
}

//TODO: check spec->length
t_fmt_spec	*ft_parse_spec(const char *fmt_str, va_list args)
{
	t_fmt_spec	*spec;
	int			len;

	(void) args;
	spec = malloc(sizeof(t_fmt_spec));
	if (!spec)
		return (NULL);
	len = ft_spec_length(fmt_str);
	spec->raw = ft_substr(fmt_str, 0, len);
	ft_fill_spec(spec, args);
	if (!ft_strchr(PF_SPECIFIERS, spec->specifier))
	{
		ft_free_spec(spec);
		return (NULL);
	}
	return (spec);
}
