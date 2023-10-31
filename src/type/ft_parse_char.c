/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:18:49 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/26 16:05:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_char(va_list args)
{
	char	*str;
	char	c;

	c = va_arg(args, int);
	str = ft_calloc(2, sizeof(char));
	str[0] = c;
	return (str);
}
