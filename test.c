/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:10:29 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/01 20:13:22 by kiroussa         ###   ########.fr       */
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
//	test("This %% is %% a %% dumb %% test");
//	test("%meow");
	test("%-5s", "42");
	test("%+5s", "42");
	return (0);
}

/*
int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	ft_printf("%s", "Hello World!");
	test("%x", 42);
	test("%x", -42);
	test("% x", 42);
	test("% x", -42);
	test("%+x", 42);
	test("%+x", -42);
	test("%+ x", 42);
	test("%+ x", -42);
	test("% +x", 42);
	test("% +x", -42);
	
	test("%5s", "42");
	test("%-5s", "42");
	test("%+5s", "42");
	test("%5s", "42");
	test("%-5d", 42);
	test("%+5d", 42);
	test("%-+5d", 42);
	test("%+-5d", 42);
	//test("%03.3x", 6983);
	test(" %p ", 17);
	test(" %p %p ", LONG_MIN, LONG_MAX);
	test(" %p %p ", INT_MIN, INT_MAX);
	test(" %p %p ", ULONG_MAX, -ULONG_MAX);
	test(" %p %p ", 0, 0);
	return (0);
}
*/
