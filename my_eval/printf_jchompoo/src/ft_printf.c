/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:17:03 by root              #+#    #+#             */
/*   Updated: 2023/01/21 17:36:56 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, str);
	if (str == NULL)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			len += check_type(*(str + 1), args);
			str++;
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

int	check_type(int c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += convert_int(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'p')
		len += convert_p(va_arg(args, unsigned long));
	else if (c == 'u')
		len += convert_u(va_arg(args, unsigned int));
	else if (c == 'x')
		len += convert_x(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		len += convert_x(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}
