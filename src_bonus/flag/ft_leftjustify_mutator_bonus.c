/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftjustify_mutator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:06:29 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 06:07:08 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_leftjustify_mutator(t_fmt_spec *spec, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (spec->width > len)
	{
		tmp = ft_strnew(spec->width);
		ft_memset(tmp, ' ', spec->width);
		ft_memcpy(tmp, str, len);
		free(str);
		return (tmp);
	}
	return (str);
}
