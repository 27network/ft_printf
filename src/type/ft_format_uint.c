/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:24:08 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/04 22:47:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_uint(t_fmt_spec *spec, va_list args)
{
	unsigned int	n;
	char			*str;

	n = va_arg(args, unsigned int);
	if (n == 0 && spec->precision == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa(n);
	return (str);
}
