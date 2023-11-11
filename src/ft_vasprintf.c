/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 07:59:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_append(char **str_ptr, char *str, int len)
{
	char	*buffer;

	if (*str_ptr == NULL)
	{
		*str_ptr = ft_strnew(len);
		ft_memcpy(*str_ptr, str, len);
	}
	else
	{
		buffer = ft_strnjoin(*str_ptr, str, len);
		free(*str_ptr);
		*str_ptr = buffer;
	}
}

static int	ft_handle_spec(
		char **str_ptr,
		const char *fmt,
		int *i,
		va_list args
) {
	t_fmt_spec	*spec;
	char		*final_fmt;
	int			len;

	spec = ft_parse_spec(fmt, args);
	if (!spec)
		return (0);
	*i += 1 + ft_strlen(spec->raw);
	final_fmt = ft_format_spec(spec, args, &len);
	ft_free_spec(spec);
	ft_append(str_ptr, final_fmt, len);
	free(final_fmt);
	return (len);
}

static int	ft_copyback(
		char **str_ptr,
		const char *fmt,
		int current_idx,
		int *last_i
) {
	char	*tmp;
	int		length;

	if (*last_i == -1)
		return (0);
	tmp = ft_substr(fmt, *last_i, current_idx - *last_i);
	*last_i = -1;
	if (!tmp)
		return (0);
	ft_append(str_ptr, tmp, ft_strlen(tmp));
	length = ft_strlen(tmp);
	free(tmp);
	return (length);
}

int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	int	len;
	int	i;
	int	last_i;

	if (!fmt)
		return (-1);
	len = 0;
	i = 0;
	last_i = -1;
	*str_ptr = NULL;
	while (fmt[i])
	{
		if (fmt[i] == *PF_FORMAT_SYMBOL)
			len += ft_copyback(str_ptr, fmt, i, &last_i);
		if (fmt[i] == *PF_FORMAT_SYMBOL)
			len += ft_handle_spec(str_ptr, &fmt[i] + 1, &i, args);
		else
		{
			if (last_i == -1)
				last_i = i;
			i++;
		}
	}
	len += ft_copyback(str_ptr, fmt, i, &last_i);
	return (len);
}
