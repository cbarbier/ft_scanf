/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:46:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/03/07 18:40:41 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{
	char	str[100];
	int		a;
	char	c;

	ft_bzero(str, 100 * sizeof(char));
	ft_scanf(0, "%s%d:%c\n", str, &a, &c);
	ft_printf("%s %d %c", str, a, c);
	return (0);
}
