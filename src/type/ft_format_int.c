/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:56:43 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/05 02:19:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static char	*ft_pad_int(t_fmt_spec *spec, char *old, int neg)
{
	char	*str;

	if (spec->flags & PF_ZERO_PAD && spec->precision == -1)
		str = ft_pad_left(old, spec->width, '0');
	else
		str = ft_pad_left(old, spec->width, ' ');
	return (str);
}

char	*ft_format_int(t_fmt_spec *spec, va_list args)
{
	int		n;
	char	*str;
	char	*tmp;
	int		neg;

	n = va_arg(args, int);
	neg = n < 0;
	if (neg)
		n = -n;
	if (n == 0 && spec->precision == 0)
		str = ft_strdup("");
	else
		str = ft_lltoa(n);
	tmp = ft_pad_int(spec, str, neg);
	free(str);
	return (tmp);
}
