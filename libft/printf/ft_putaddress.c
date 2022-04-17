/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 03:41:18 by aball             #+#    #+#             */
/*   Updated: 2022/03/02 17:47:01 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_write(unsigned long long n)
{
	if (n > 9)
		print_putchar(n + 87);
	else
		print_putnbr(n);
	return (1);
}

static int	hexer(unsigned long long n)
{
	static int	i;

	i = 0;
	if (n > 15)
		hexer(n / 16);
	i += hex_write(n % 16);
	return (i);
}

int	ft_putaddress(unsigned long long ptr)
{
	int	c;

	c = print_putstr("0x");
	c += hexer((unsigned long long)ptr);
	return (c);
}
