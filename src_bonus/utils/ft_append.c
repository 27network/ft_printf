/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 01:34:12 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 01:35:06 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_append(char **dest, int dest_len, char *src, int src_len)
{
	char	*buffer;

	if (*dest == NULL)
	{
		*dest = ft_strnew(src_len);
		ft_memcpy(*dest, src, src_len);
	}
	else
	{
		buffer = ft_strnjoin(*dest, dest_len, src, src_len);
		free(*dest);
		*dest = buffer;
	}
}
