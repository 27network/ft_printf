/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:44:36 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/22 15:34:16 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prepend_sign(t_fmt_spec *spec, char *str, int neg)
{
	char	*sign;
	char	*tmp;

	(void)spec;
	if (neg)
		sign = ft_strdup("-");
	else
		return (ft_strdup(str));
	tmp = ft_strjoin(sign, str);
	free(sign);
	return (tmp);
}
