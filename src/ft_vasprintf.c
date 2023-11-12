/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 02:50:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_spec(
		char **str_ptr,
		t_fmt_spec *spec,
		va_list args,
		int length
) {
	char		*final_fmt;
	int			len;

	if (!spec)
		return (0);
	final_fmt = ft_format_spec(spec, args, &len);
	ft_free_spec(spec);
	ft_append(str_ptr, length, final_fmt, len);
	free(final_fmt);
	return (len);
}

static int	ft_copyback(
		char **str_ptr,
		const char *fmt,
		int copy_length,
		int dest_len
) {
	char	*tmp;
	int		length;

	tmp = ft_substr(fmt, 0, copy_length);
	if (!tmp)
		return (0);
	ft_append(str_ptr, dest_len, tmp, ft_strlen(tmp));
	length = ft_strlen(tmp);
	free(tmp);
	return (length);
}

static t_str	*ft_handle_format(
		const char *fmt,
		int *i,
		int *last_i,
		va_list args
) {
	return (NULL);
}

int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	t_str	str;
	int		i;
	int		last_i;

	if (!fmt)
		return (-1);
	ft_str_init(&str, str_ptr);
	i = 0;
	last_i = -1;
	while (fmt[i])
	{
		if (fmt[i] == *PF_FORMAT_SYMBOL)
			ft_str_append(&str, ft_handle_format(fmt, &i, &last_i, args));
		else
		{
			if (last_i == -1)
				last_i = i;
			i++;
		}
	}
	if (last_i != -1)
		str.length += ft_copyback(str_ptr, fmt + last_i, i - last_i, str.length);
	return (str.length);
}
