/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 02:18:32 by kiroussa         ###   ########.fr       */
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

int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	int			len;
	int			i;
	int			last_i;

	if (!fmt)
		return (-1);
	len = 0;
	i = 0;
	last_i = -1;
	*str_ptr = NULL;
	while (fmt[i])
	{
		if (fmt[i] == *PF_FORMAT_SYMBOL)
		{
			if (last_i != -1)
				len += ft_copyback(str_ptr, fmt + last_i, i - last_i, len);
			if (last_i != -1)
				last_i = -1;
			len += ft_handle_spec(str_ptr, ft_new_spec(&fmt[i] + 1, &i, args), args, len);
		}
		else
		{
			if (last_i == -1)
				last_i = i;
			i++;
		}
	}
	if (last_i != -1)
		len += ft_copyback(str_ptr, fmt + last_i, i - last_i, len);
	return (len);
}
