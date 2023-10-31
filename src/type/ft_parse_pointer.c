/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:20:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/27 22:56:04 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_pointer(const char *base, va_list args)
{
	char				*str;
	char				*final;
	unsigned long long	ptr;

	ptr = (unsigned long long) va_arg(args, void *);
	if (ptr == 0)
		return (ft_strdup("(nil)"));
	str = ft_lltoa_base(ptr, base);
	final = ft_strjoin("0x", str);
	free(str);
	return (final);
}
