/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:15:36 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/26 11:46:22 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "X.h"

static int			ft_isdynamic(int fractal)
{
	return (fractal == JUL || fractal == GEO);
}

static void			ft_input_scale(ENV *e, int button)
{
	if (button == 1 || button == 5)
	{
		e->zoom *= SCALE;
		e->offset.x -= (e->input.center.x - e->offset.x) * SCALE
			- (e->input.center.x - e->offset.x);
		e->offset.y -= (e->input.center.y - e->offset.y) * SCALE
			+ (e->offset.y - e->input.center.y);
		e->ppmove *= 1.15;
	}
	else if ((button == 2 || button == 4))
	{
		e->zoom /= SCALE;
		e->offset.x -= (e->input.center.x - e->offset.x) / SCALE
			- (e->input.center.x - e->offset.x);
		e->offset.y -= (e->input.center.y - e->offset.y) / SCALE
			+ (e->offset.y - e->input.center.y);
		if (e->ppmove > 20)
			e->ppmove /= 1.15;
	}
	e->zoominv = 1.0 / e->zoom;
}

int					ft_motionhook(int x, int y, void *param)
{
	mlx_clear_window(((ENV *)param)->mlxvar.mlx, ((ENV *)param)->mlxvar.win);
	if (ft_isdynamic(((ENV *)param)->input.fractal)
			&& !((ENV *)param)->input.pause)
	{
		((ENV *)param)->constc.x = x * ((ENV *)param)->zoominv;
		((ENV *)param)->constc.y = y * ((ENV *)param)->zoominv;
		ft_fractalize((ENV *)param);
	}
	((ENV *)param)->input.focus.x = (float)x;
	((ENV *)param)->input.focus.y = (float)y;
	ft_itoa_cust(x, &((ENV *)param)->input.str[X]);
	ft_itoa_cust(y, &((ENV *)param)->input.str[Y]);
	ft_display((ENV *)param);
	return (0);
}

int					ft_dealbutton(int button, int x, int y, void *param)
{
	int		new_fractal;

	mlx_clear_window(((ENV *)param)->mlxvar.mlx, ((ENV *)param)->mlxvar.win);
	new_fractal = 0;
	if (x >= MENU_START && x < WIN_W && button == Button1
			&& (ft_select_fractal((ENV *)param, y, NULL)))
		ft_itoa_cust(((ENV *)param)->input.iteration,
				&((ENV *)param)->input.str[ITE]);
	else if (x >= 0 && x < MENU_START && y >= 0 && y < WIN_H
			&& (button == Button1
				|| button == Button2
				|| button == Button4
				|| button == Button5))
	{
		((ENV *)param)->input.center.x = x;
		((ENV *)param)->input.center.y = y;
		ft_input_scale((ENV *)param, button);
	}
	ft_fractalize(param);
	ft_display(param);
	return (0);
}
