/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:39:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 03:41:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format(const char *format, ...)
{
	va_list	args;
	char	*str;

	va_start(args, format);
	str = ft_vformat(format, args);
	va_end(args);
	return (str);
}
