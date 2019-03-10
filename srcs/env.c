/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:21:56 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/27 11:42:43 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_update_display_strings(ENV *e)
{
	ft_itoa_cust(e->input.red, &e->input.str[R]);
	ft_itoa_cust(e->input.green, &e->input.str[G]);
	ft_itoa_cust(e->input.blue, &e->input.str[B]);
	ft_itoa_cust(e->input.focus.x, &e->input.str[X]);
	ft_itoa_cust(e->input.focus.y, &e->input.str[Y]);
	ft_itoa_cust(e->input.iteration, &e->input.str[ITE]);
}

void		ft_reset(ENV *e)
{
	static int	iteration[7] = {100, 130, 1, 100, 100, 100, 100};
	static int	constx[7] = {0, 52, 0, 0, 0, -3, 95};
	static int	consty[7] = {0, 72, 0, 0, 0, -31, 49};
	int			half_w;
	int			half_h;

	half_w = (float)MENU_START * 0.5;
	half_h = (float)WIN_H * 0.5;
	ft_memset(&e->clr, 0xFFFFFF, 7 * sizeof(int));
	ft_4fvinit(&e->input.focus, half_w, half_h, 0);
	e->input.iteration = iteration[e->input.fractal];
	e->ppmove = 20;
	e->zoom = (e->input.fractal == BAR ? half_w : MENU_START) * 0.2;
	e->zoominv = 1.0 / e->zoom;
	e->offset.x = e->input.focus.x;
	e->offset.y = e->input.fractal == BAR ? 0 : e->input.focus.y;
	e->input.red = e->input.fractal == BAR ? 0xA0 : 255;
	e->input.green = e->input.fractal == BAR ? 0xDB : 255;
	e->input.blue = e->input.fractal == BAR ? 0x8E : 255;
	e->input.theme = BLOCK;
	e->input.pause = 1;
	e->constc.x = constx[e->input.fractal] * e->zoominv;
	e->constc.y = consty[e->input.fractal] * e->zoominv;
	e->clr[e->input.fractal] = COL_SELECT;
	ft_update_display_strings(e);
}

int			ft_getenv(ENV *e)
{
	int		i;
	float	half_w;
	float	half_h;

	i = 0;
	half_w = (float)MENU_START * 0.5;
	half_h = (float)WIN_H * 0.5;
	ft_4fvinit(&e->cmplx, 0, 0, 0);
	ft_fill_bckgrnd(e, 80, 1);
	ft_fill_bckgrnd(e, WIN_H, 2);
	e->color = 0xFFFFFF;
	e->input.pause = 1;
	e->input.color_inv = 0;
	e->input.dir = -1;
	ft_4fvinit(&e->input.center, half_w, half_h, 0);
	ft_bzero(e->mlxvar.ptr, WIN_W * WIN_H * 4);
	return (0);
}
