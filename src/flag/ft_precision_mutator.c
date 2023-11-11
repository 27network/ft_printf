/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_mutator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:57:51 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 06:06:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_mutator_str(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (spec->precision != -1 && spec->precision < len)
	{
		tmp = ft_strnew(spec->precision);
		ft_memcpy(tmp, str, spec->precision);
		free(str);
		return (tmp);
	}
	return (str);
}

char	*ft_precision_mutator_int(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;
	int		neg;

	neg = *str == '-';
	len = ft_strlen(str) - neg;
	if (spec->precision > len)
	{
		tmp = ft_strnew(spec->precision + neg);
		ft_memset(tmp, '0', spec->precision + neg);
		ft_memcpy(tmp + spec->precision - len + neg, str + neg, len);
		if (neg)
			tmp[0] = '-';
		free(str);
		return (tmp);
	}
	return (str);
}
