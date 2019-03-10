/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geonerd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:57:29 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:08:22 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static void				ft_set_complex(ENV *e, int row, int col)
{
	e->c.x = (float)((col - e->offset.x) * e->zoominv);
	e->c.y = (float)((row - e->offset.y) * e->zoominv);
}

int						ft_geonerd(ENV *e, int row, int col)
{
	int					iteration;
	t_4fvect			square;

	iteration = 5;
	ft_set_complex(e, row, col);
	ft_4fvinit(&square, 0, 0, 0);
	while (iteration < e->input.iteration && square.x + square.y < 4)
	{
		ft_4fvcpy(&e->cmplx, e->c);
		square.x = e->cmplx.x * e->cmplx.x;
		square.y = e->cmplx.y * e->cmplx.y;
		e->c.x = cos(square.y) + e->constc.x;
		e->c.y = sin(square.x) + e->constc.y;
		iteration += 5;
	}
	ft_put_to_img(e, row, col, ft_getcolor(e, iteration));
	return (0);
}
