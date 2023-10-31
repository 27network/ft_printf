/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/31 20:57:05 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_spec(char **str_ptr, const char *fmt, va_list args)
{
	t_fmt_spec	*spec;
	int			len;

	spec = ft_parse_spec(fmt, args);
	if (!spec)
		return (0);
	len = 0;
	(void)str_ptr;
	free(spec);
	return (len);
}

static int	ft_copyback(
		char **str_ptr,
		const char *fmt,
		int current_idx,
		int *last_nofmt_idx
) {
	char	*tmp;

	if (*last_nofmt_idx == -1)
		return (0);
	tmp = ft_substr(fmt, );
	*last_nofmt_idx = -1;
}

//FIXME: we might be overallocating with ft_calloc if fmt has %%
int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	int	len;
	int	i;
	int	last_nofmt_idx;

	len = 0;
	i = -1;
	last_nofmt_idx = -1;
	*str_ptr = ft_calloc(ft_strlen(fmt) + 1, sizeof(char));
	if (!*str_ptr)
		return (-1);
	while (fmt[++i])
	{
		if (fmt[i] == *PF_FORMAT_SYMBOL)
		{
			len += ft_copyback(str_ptr, fmt, &last_nofmt_idx);
			len += ft_handle_spec(str_ptr, fmt, args);
		}
		else if (last_nofmt_idx == -1)
			last_nofmt_idx = i;
	}
	len += ft_copyback(str_ptr, fmt, &last_nofmt_idx);
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
