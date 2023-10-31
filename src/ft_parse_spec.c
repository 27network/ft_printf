/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:47:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/31 20:20:39 by kiroussa         ###   ########.fr       */
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
			spec->flags |= LEFT_JUSTIFY;
		else if (format[i] == PF_FLAGS[1])
			spec->flags |= ZERO_PAD;
		else if (format[i] == PF_FLAGS[2])
			spec->flags |= SPACE;
		else if (format[i] == PF_FLAGS[3])
			spec->flags |= HASH;
		else if (format[i] == PF_FLAGS[4])
			spec->flags |= PLUS;
		i++;
	}
	return (i);
}

t_fmt_spec	*ft_parse_spec(const char *format, va_list args)
{
	t_fmt_spec	*spec;
	char		*rest;

	(void) args;
	spec = malloc(sizeof(t_fmt_spec));
	if (!spec)
		return (NULL);
	spec->raw = ft_strdup(format);
	spec->len = ft_strlen(format);
	rest = ft_substr(format, ft_fill_flags(format, spec), spec->len);
	ft_putstr("rest: ");
	ft_putendl(rest);
	free(rest);
	return (spec);
}
