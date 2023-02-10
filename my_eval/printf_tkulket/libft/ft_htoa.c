/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:24:33 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/04 16:39:34 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_htoa(unsigned int n)
{
	char	*tmp;
	size_t	d;

	d = ft_countdigit_h(n);
	tmp = malloc(sizeof(char) * (d + 1));
	if (!tmp)
		return (NULL);
	dec_to_hex(n, 0, tmp);
	if (d > 1)
		reverse_digit(tmp);
	if (n == 0)
		tmp[0] = '0';
	tmp[d] = '\0';
	return (tmp);
}
