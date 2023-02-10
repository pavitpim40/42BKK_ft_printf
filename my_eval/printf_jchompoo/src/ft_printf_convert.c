/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:01:56 by jchompoo          #+#    #+#             */
/*   Updated: 2023/01/21 18:25:47 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_int(int c)
{
	int		i;
	char	*str;

	str = ft_itoa(c);
	i = ft_putstr(str);
	free(str);
	return (i);
}

int	convert_x(unsigned int c, int f)
{
	if (c >= 16)
	{
		convert_x(c / 16, f);
		convert_x(c % 16, f);
	}
	else if (c <= 9)
		ft_putchar(c + '0');
	else
	{
		if (f == 'x')
			ft_putchar(c - 10 + 'a');
		else
			ft_putchar(c - 10 + 'A');
	}
	return (x_len(c, 16));
}

int	convert_u(unsigned int c)
{
	if (c >= 10)
	{
		convert_u(c / 10);
		convert_u(c % 10);
	}
	else
		ft_putchar(c + '0');
	return (x_len(c, 10));
}

int	convert_p(unsigned long c)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (c == 0)
		len += write(1, "0", 1);
	else
	{
		ft_put_ptr(c);
		len += p_len(c, 16);
	}
	return (len);
}
