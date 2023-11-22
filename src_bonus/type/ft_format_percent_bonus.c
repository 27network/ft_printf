/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:57 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/04 23:03:10 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_percent(t_fmt_spec *spec, va_list args)
{
	char	*str;

	(void)args;
	(void)spec;
	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '%';
	return (str);
}
