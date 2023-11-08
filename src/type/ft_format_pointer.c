/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:47:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/04 23:03:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_pointer(t_fmt_spec *spec, va_list args)
{
	unsigned long long	n;
	char				*str;
	char				*tmp;
	int					i;

	n = va_arg(args, unsigned long long);
	if (n == 0 && spec->precision == 0)
		str = ft_strdup("");
	else
		str = ft_ulltoa_base(n, "0123456789abcdef");
	if (!str)
		return (NULL);
	i = 16 - ft_strlen(str);
	while (i-- > 0)
	{
		tmp = ft_strjoin("0", str);
		free(str);
		if (!tmp)
			return (NULL);
		str = tmp;
	}
	return (str);
}
