/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:44:36 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 03:47:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prepend_sign(t_fmt_spec *spec, char *str, int neg)
{
	char	*sign;
	char	*tmp;

	if (neg)
		sign = ft_strdup("-");
	else if (spec->flags & PF_PLUS)
		sign = ft_strdup("+");
	else if (spec->flags & PF_SPACE)
		sign = ft_strdup(" ");
	else
		return (ft_strdup(str));
	tmp = ft_strjoin(sign, str);
	free(sign);
	return (tmp);
}
