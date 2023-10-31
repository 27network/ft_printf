/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:42:09 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 02:57:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define LOWERCASE_HEX "0123456789abcdef"
#define UPPERCASE_HEX "0123456789ABCDEF"

// Missing: digits (we use ft/string.h:ft_isdigit)
// 			* (use va_arg for flag input)
#define FLAGS "-.# +" 

// Missing: f eE gG (doubles), 
// 			n (number of chars for this printf), 
// 			o (octal)
#define TYPES "cspdiuxX%"

static char	*ft_extract_fmt(const char *format)
{
	int		i;
	char	*fmt;
	char	c;

	i = 0;
	while (format[i])
	{
		c = format[i];
		if (ft_strchr(TYPES, c))
			break ;
		if (!ft_isdigit(c) && !ft_strchr(FLAGS, c))
			break ;
		i++;
	}
	if (format[i] && !ft_strchr(TYPES, format[i]))
		return (NULL);
	fmt = ft_substr(format, 0, i + 1);
	return (fmt);
}

static char	*ft_parse_type(char *type, va_list args, int *length)
{
	char	*type_str;

	if (!ft_strcmp(type, PF_FORMAT_SYMBOL))
		type_str = ft_strdup(PF_FORMAT_SYMBOL);
	else if (!ft_strcmp(type, "c"))
		type_str = ft_parse_char(args);
	else if (!ft_strcmp(type, "s"))
		type_str = ft_parse_string(args);
	else if (!ft_strcmp(type, "p"))
		type_str = ft_parse_pointer(LOWERCASE_HEX, args);
	else if (!ft_strcmp(type, "d") || !ft_strcmp(type, "i"))
		type_str = ft_parse_int(args);
	else if (!ft_strcmp(type, "u"))
		type_str = ft_parse_uint(args);
	else if (!ft_strcmp(type, "x"))
		type_str = ft_parse_hex(LOWERCASE_HEX, args);
	else if (!ft_strcmp(type, "X"))
		type_str = ft_parse_hex(UPPERCASE_HEX, args);
	else
		type_str = ft_strdup("");
	*length += ft_strlen(type_str);
	if (!ft_strcmp(type, "c") && !*type_str)
		*length += 1;
	free(type);
	return (type_str);
}

/**
 * @brief	Transforms the format string based on the previous one
 */
static char	*ft_pre_flag(char *fmt, va_list args)
{
	(void)args;
	return (fmt);
}

/**
 * @brief	Transforms the formatted string based on the format flags	
 */
static char	*ft_post_flag(char *str, char *fmt, va_list args, int *len)
{
	(void)fmt;
	(void)args;
	(void)len;
	return (str);
}

char	*ft_parse(const char *format, va_list args, int *len, int *c)
{
	char	*fmt;
	char	*type_str;
	char	*str;

	*c = 0;
	fmt = ft_extract_fmt(format);
	if (!fmt)
		return (ft_strdup(""));
	*c = ft_strlen(fmt);
	fmt = ft_pre_flag(fmt, args);
	type_str = malloc(sizeof(char) * 2);
	if (type_str)
	{
		type_str[0] = fmt[ft_strlen(fmt) - 1];
		type_str[1] = '\0';
		str = ft_parse_type(type_str, args, len);
		str = ft_post_flag(str, fmt, args, len);
	}
	else
		str = ft_strjoin(PF_FORMAT_SYMBOL, fmt);
	free(fmt);
	return (str);
}
