/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_spec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:18:51 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 01:03:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt_spec	*ft_new_spec(
		const char *fmt,
		int *i,
		va_list args
) {
	t_fmt_spec	*spec;

	spec = ft_parse_spec(fmt, args);
	if (spec)
		*i += 1 + ft_strlen(spec->raw);
	return (spec);
}

void	ft_free_spec(t_fmt_spec *spec)
{
	free(spec->raw);
	free(spec->length);
	free(spec);
}
