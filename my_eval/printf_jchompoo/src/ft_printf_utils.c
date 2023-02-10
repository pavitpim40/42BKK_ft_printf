/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:00:07 by jchompoo          #+#    #+#             */
/*   Updated: 2023/02/04 16:54:11 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	x_len(unsigned int c, int base)
{
	int	i;

	if (c == 0)
		return (1);
	i = 0;
	while (c != 0)
	{
		i++;
		c /= base;
	}
	return (i);
}

int	p_len(unsigned long c, int base)
{
	int	i;

	if (c == 0)
		return (1);
	i = 0;
	while (c != 0)
	{
		i++;
		c /= base;
	}
	return (i);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar((num - 10 + 'a'));
	}
}
