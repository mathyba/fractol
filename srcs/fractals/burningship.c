/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:11:51 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:07:39 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_set_complex(ENV *e, int row, int col)
{
	e->c.x = (float)((col - e->offset.x) * e->zoominv);
	e->c.y = (float)((row - e->offset.y) * e->zoominv);
}

int			ft_burningship(ENV *e, int row, int col)
{
	t_4fvect		new_cmplx;
	int				iteration;
	t_4fvect		tmp;

	ft_4fvinit(&new_cmplx, 0, 0, 0);
	ft_4fvinit(&tmp, 0, 0, 0);
	iteration = 5;
	ft_set_complex(e, row, col);
	while (iteration < e->input.iteration && tmp.x + tmp.y < 4)
	{
		e->cmplx.x = ft_fabs(new_cmplx.x);
		e->cmplx.y = ft_fabs(new_cmplx.y);
		ft_4fvinit(&tmp, e->cmplx.x * e->cmplx.x, e->cmplx.y * e->cmplx.y, 0);
		new_cmplx.x = tmp.x - tmp.y + e->c.x;
		e->cmplx.x += e->cmplx.x;
		new_cmplx.y = e->cmplx.x * e->cmplx.y + e->c.y;
		iteration += 5;
	}
	ft_put_to_img(e, row, col, ft_getcolor(e, iteration));
	return (0);
}
