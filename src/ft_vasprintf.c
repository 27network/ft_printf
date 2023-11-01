/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:26:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/01 19:43:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_append(char **str_ptr, char *str)
{
	char	*buffer;

	if (*str_ptr == NULL)
		*str_ptr = ft_strdup(str);
	else
	{
		buffer = ft_strjoin(*str_ptr, str);
		free(*str_ptr);
		*str_ptr = buffer;
	}
}

static void	ft_free_spec(t_fmt_spec *spec)
{
	free(spec->raw);
	free(spec->length);
	free(spec);
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
	*i += 1;
	final_fmt = ft_strdup("%");
	ft_free_spec(spec);
	len = ft_strlen(final_fmt);
	ft_append(str_ptr, final_fmt);
	free(final_fmt);
	return (len);
}

static int	ft_copyback(
		char **str_ptr,
		const char *fmt,
		int current_idx,
		int *last_nofmt_idx
) {
	char	*tmp;
	int		length;

	if (*last_nofmt_idx == -1)
		return (0);
	tmp = ft_substr(fmt, *last_nofmt_idx, current_idx - *last_nofmt_idx);
	*last_nofmt_idx = -1;
	if (!tmp)
		return (0);
	ft_append(str_ptr, tmp);
	length = ft_strlen(tmp);
	free(tmp);
	return (length);
}

int	ft_vasprintf(char **str_ptr, const char *fmt, va_list args)
{
	int	len;
	int	i;
	int	last_nofmt_idx;

	len = 0;
	i = -1;
	last_nofmt_idx = -1;
	*str_ptr = NULL;
	while (fmt[++i])
	{
		if (fmt[i] == *PF_FORMAT_SYMBOL)
		{
			len += ft_copyback(str_ptr, fmt, i, &last_nofmt_idx);
			len += ft_handle_spec(str_ptr, fmt, &i, args);
		}
		else if (last_nofmt_idx == -1)
			last_nofmt_idx = i;
	}
	len += ft_copyback(str_ptr, fmt, i, &last_nofmt_idx);
	return (len);
}
