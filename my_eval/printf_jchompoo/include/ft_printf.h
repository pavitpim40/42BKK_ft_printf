/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:40:19 by jchompoo          #+#    #+#             */
/*   Updated: 2023/01/21 18:25:26 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//# include "libft.h"

void	ft_put_ptr(unsigned long num);
int		ft_printf(const char *str, ...);
int		convert_int(int c);
int		ft_putchar(int c);
int		check_type(int c, va_list args);
int		ft_putstr(char *str);
int		convert_x(unsigned int c, int f);
int		x_len(unsigned int c, int base);
int		convert_u(unsigned int c);
int		convert_p(unsigned long c);
int		p_len(unsigned long c, int base);
char	*ft_itoa(int a);

#endif