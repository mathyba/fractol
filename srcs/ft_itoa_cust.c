/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_cust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:27:39 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:01:03 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_itoa_cust(int n, char (*str)[10])
{
	int		len;

	len = ft_nblen(n, 10);
	if (n < 0)
		++len;
	(*str)[len] = 0;
	while (len-- && n / 10)
	{
		(*str)[len] = (char)(ft_abs(n % 10) + '0');
		n /= 10;
	}
	(*str)[len] = (char)((n > 0 ? n % 10 : -n % 10) + '0');
	if (n < 0)
		(*str)[0] = '-';
}
