/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:47:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/01 20:12:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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
*/
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
	printf("spec: %s\n", spec->raw);
//	rest = ft_substr(fmt_str, ft_fill_flags(fmt_str, spec), );
	spec->length = malloc(1);
//	free(rest);
	return (spec);
}
