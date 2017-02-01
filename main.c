/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:46:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/01/27 14:17:29 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	int x;
	int y;
	int n;
	char* l = setlocale(LC_ALL, "");

	x = 0;
	y = 0;
	/*
	if (l)
		x = printf("pf{%S}\n", L"Á±≥");
	y = ft_printf("ft{%S}\n", L"Á±≥");
	printf("%x%x%x%x%x\n",20, 1, 100, 999, 42, 999988888);
	ft_printf("%x%x%x%x%x\n",20, 1, 100, 999, 42, 999988888);
		printf(".{%.S}\n", L"42 c'est cool");
		ft_printf("%b %#B\n", 10, 10);
//		x = printf("{%S}\n", L"Á±≥");
//	y = ft_printf("ft{%10.5S}\n", L"123456");
	//ft_printf("{%b %#x last6 %b}", 945, 945, 0x80 + (945 >> 6 & 0x3f));
	//ft_printf("{%b}", 0xe0 + 15);
	//x = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	*/
/*	x = printf("pf%.4S\n", L"我是一只猫。");
	x = ft_printf("ft3*{%3*p}", 10, 0);
	x = ft_printf("ft*3{%*3p}", 10, 0);
	x = printf("3*{%3*p}", 10, 0);
	x = printf("*3{%*3p}", 10, 0);
	*/
	x = printf("{%hhld}", "128");
/*	y = ft_printf("ft%.4S  fan%cfan\n", L"我是一只猫。", 0);
	y = ft_printf("test of * bonus{%*.*d}", -10, 5,  10);
	y = ft_printf("ft{%.*s}", -5, "42");
	*/
	y = ft_printf("{%hhld}", "128");
//	printf("pff%S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	ft_printf("ftf%S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	printf("pf:%d ft:%d, n:%d\n", x, y, n);
	return (0);
}

