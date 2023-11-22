/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:22:28 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 17:46:09 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*ft_str_create(char *string, size_t length)
{
	t_str	*str;

	str = (t_str *)malloc(sizeof(t_str));
	if (!str)
		return (NULL);
	ft_str_init(str, string, length);
	return (str);
}
