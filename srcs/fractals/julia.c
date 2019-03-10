/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:55:31 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/26 11:46:20 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_set_complex(ENV *e, int row, int col)
{
	e->c.x = (float)((col - e->offset.x) * e->zoominv);
	e->c.y = (float)((row - e->offset.y) * e->zoominv);
}

int					ft_julia(ENV *e, int row, int col)
{
	int				iteration;
	t_4fvect		square;

	iteration = 5;
	ft_set_complex(e, row, col);
	ft_4fvinit(&square, 0, 0, 0);
	while (iteration < e->input.iteration && square.x + square.y < 4)
	{
		ft_4fvcpy(&e->cmplx, e->c);
		square.x = e->cmplx.x * e->cmplx.x;
		square.y = e->cmplx.y * e->cmplx.y;
		e->c.x = square.x - square.y + e->constc.x;
		e->cmplx.x += e->cmplx.x;
		e->c.y = e->cmplx.x * e->cmplx.y + e->constc.y;
		iteration += 5;
	}
	ft_put_to_img(e, row, col, ft_getcolor(e, iteration));
	return (0);
}
