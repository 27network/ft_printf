/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:27:01 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 07:28:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	char	*str;
	int		len;

	str = NULL;
	len = ft_vasprintf(&str, format, args);
	if (len > 0 && str)
		write(fd, str, len);
	if (str)
		free(str);
	return (len);
}
