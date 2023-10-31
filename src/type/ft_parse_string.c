/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:20:01 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 16:05:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	return (str);
}
