/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:10:29 by kiroussa          #+#    #+#             */
/*   Updated: 2023/11/11 07:29:41 by kiroussa         ###   ########.fr       */
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

	test("%hhs", "testing testing");
	test("");
	test("%s", "testing testing");
	test("Hello, %s!ayahadhahd", "world");

	/*
		TEST(1, print("%-1c", '0'));
	TEST(2, print(" %-2c ", '0'));
	TEST(3, print(" %-3c", '0' - 256));
	TEST(4, print("%-4c ", '0' + 256));
	TEST(5, print(" %-1c %-2c %-3c ", '0', 0, '1'));
	TEST(6, print(" %-1c %-2c %-3c ", ' ', ' ', ' '));
	TEST(7, print(" %-1c %-2c %-3c ", '1', '2', '3'));
	TEST(8, print(" %-1c %-2c %-3c ", '2', '1', 0));
	TEST(9, print(" %-1c %-2c %-3c ", 0, '1', '2'));
*/
	test(" %-1c %-2c %-3c ", '0', 0, '1');
	test(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	test(" %-1c %-2c %-3c ", '1', '2', '3');
	test(" %-1c %-2c %-3c ", '2', '1', 0);
	test(" %-1c %-2c %-3c ", 0, '1', '2');

	//test("%#x", 0);
	/*
	test("%-5c", 0);
	test("%-.5c", 0);
	
	int	awa;
	int	uwu;

	awa = 69;
	uwu = 420;
	test("%p %p", &awa, &uwu);
	test("%5.p %5.p", &awa, &uwu);
	test("%10.p %5.p", &awa, &uwu);
	*/
//	test("%%04.2i 42 == |%04.2i|", 42);
//	test("%%04.3i 42 == |%04.3i|", 42);
	/*
	test("%+1d", 42);
	test("%d", -42);
	test("% d", 42);
	test("% d", -42);
	test("%+d", 42);
	test("%+d", -42);
	test("%+ d", 42);
	test("%+ d", -42);
	test("% +d", 42);
	test("% +d", -42);
	*/
	/*
	test("%5s", "42");
	test("%-5s", "42");
	test("%+5s", "42");
	test("%5s", "42");
	test("%-5d", 42);
	test("%+5d", 42);
	test("%-+5d", 42);
	test("%+-5d", 42);
	test("%03.3x", 6983);
	test(" %p ", 17);
	test(" %p %p ", LONG_MIN, LONG_MAX);
	test(" %p %p ", INT_MIN, INT_MAX);
	test(" %p %p ", ULONG_MAX, -ULONG_MAX);
	test(" %p %p ", 0, 0);
*/
	return (0);
}
