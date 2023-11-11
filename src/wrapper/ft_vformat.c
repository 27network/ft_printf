/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:41:15 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 03:42:21 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_vformat(const char *format, va_list args)
{
	char	*str;

	str = NULL;
	if (ft_vasprintf(&str, format, args) == -1)
		return (NULL);
	return (str);
}
