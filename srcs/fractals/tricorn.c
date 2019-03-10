/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:59:42 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:11:25 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void				ft_set_complex(ENV *e, int row, int col)
{
	e->c.x = (float)((col - e->offset.x) * e->zoominv);
	e->c.y = (float)((row - e->offset.y) * e->zoominv);
}

int						ft_tricorn(ENV *e, int row, int col)
{
	t_4fvect			new_cmplx;
	t_4fvect			tmp;
	int					iteration;

	ft_4fvinit(&new_cmplx, 0, 0, 0);
	ft_4fvinit(&tmp, 0, 0, 0);
	iteration = 5;
	ft_set_complex(e, row, col);
	while (iteration < e->input.iteration && tmp.x + tmp.y < 4)
	{
		ft_4fvcpy(&e->cmplx, new_cmplx);
		ft_4fvinit(&tmp, e->cmplx.x * e->cmplx.x, e->cmplx.y * e->cmplx.y, 0);
		new_cmplx.x = tmp.x - tmp.y + e->c.x;
		e->cmplx.x += e->cmplx.x;
		new_cmplx.y = -e->cmplx.x * e->cmplx.y + e->c.y;
		iteration += 5;
	}
	ft_put_to_img(e, row, col, ft_getcolor(e, iteration));
	return (0);
}
