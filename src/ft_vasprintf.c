/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/29 00:26:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_spec(char **str_ptr, const char *fmt, va_list args)
{
	t_fmt_spec	*spec;

	spec = ft_parse_spec(fmt, args);
	if (!spec)
		return (0);
	(void)spec;
	(void)str_ptr;
	return (0);
}

static char	*ft_handle_len_increase(char **str_ptr, int *len, int len_increase)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (*len + len_increase + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, *str_ptr, *len);
	free(*str_ptr);
	*str_ptr = new_str;
	*len += len_increase;
	return (*str_ptr);
}

int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	int		len;
	int		len_increase;
	char	*str;

	len = 0;
	str = ft_calloc(ft_strlen(fmt) + 1, sizeof(char));
	if (!str)
		return (-1);
	while (*fmt)
	{
		if (*fmt == *PF_FORMAT_SYMBOL)
		{
			len_increase = ft_handle_spec(&str, fmt, args);
			if (len_increase == 0)
				str[len++] = *PF_FORMAT_SYMBOL;
			str = ft_handle_len_increase(&str, &len, len_increase);
		}
		else
			str[len++] = *fmt;
	}
	*str_ptr = str;
	return (len);
}
/*
int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int		len;
	int		llen;
	char	*str;
	int		consumed;

	len = 0;
	while (*format)
	{
		if (*format == *PF_FORMAT_SYMBOL)
		{
			llen = 0;
			str = ft_parse(format + 1, args, &llen, &consumed);
			ft_write(fd, str, &llen);
			free(str);
			format += consumed;
			len += llen - 1;
		}
		else
			ft_putchar_fd(fd, *format);
		len++;
		format++;
	}
	return (len);
}
*/
