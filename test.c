/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:10:29 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/12 00:16:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

void	test(const char *str, ...)
{
	va_list	args;
	va_list	args2;
	int		i;

	va_start(args, str);
	va_copy(args2, args);
	ft_putstr("printf:    '");
	i = vprintf(str, args);
	fflush(stdout);
	ft_putstr("' (");
	ft_putnbr(i);
	ft_putendl(" chars)");
	va_end(args);
	ft_putstr("ft_printf: '");
	i = ft_vprintf(str, args2);
	ft_putstr("' (");
	ft_putnbr(i);
	ft_putendl(" chars)");
	va_end(args2);
}

int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	test(" %-1c %-2c %-3c ", '0', 0, '1');
	test(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	test(" %-1c %-2c %-3c ", '1', '2', '3');
	test(" %-1c %-2c %-3c ", '2', '1', 0);
	test(" %-1c %-2c %-3c ", 0, '1', '2');
	return (0);
}
