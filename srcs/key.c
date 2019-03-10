/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:25:54 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/27 11:38:29 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include "X.h"

static void		ft_move_and_zoom(ENV *e, int key)
{
	if (key == KEY_UP)
		e->offset.y += e->ppmove * e->input.dir;
	else if (key == KEY_DW)
		e->offset.y -= e->ppmove * e->input.dir;
	else if (key == KEY_LF)
		e->offset.x += e->ppmove * e->input.dir;
	else if (key == KEY_RT)
		e->offset.x -= e->ppmove * e->input.dir;
	else if (key == KEY_DIR)
		e->input.dir *= -1;
	else if (key == KEY_ZMIN)
	{
		e->zoom *= SCALE;
		e->ppmove *= 1.15;
	}
	else if (key == KEY_ZMOUT)
	{
		e->zoom /= SCALE;
		e->ppmove /= 1.15;
	}
	e->zoominv = 1.0 / e->zoom;
}

static void		ft_change_color(ENV *e, int key)
{
	if (key == KEY_GREEN)
		e->input.green -= 5;
	else if (key == KEY_RED)
		e->input.red -= 5;
	else if (key == KEY_BLUE)
		e->input.blue -= 5;
	else if (key == KEY_GREEN_ADD)
		e->input.green += 5;
	else if (key == KEY_RED_ADD)
		e->input.red += 5;
	else if (key == KEY_BLUE_ADD)
		e->input.blue += 5;
	else if (key == KEY_COLOR_INV && e->input.fractal != BAR)
		e->input.color_inv = e->input.color_inv ? 0 : 1;
	else
		return ;
}

static void		ft_change_iter_or_theme(ENV *e, int key)
{
	if (key == KEY_ADD)
		e->input.iteration += 5;
	else if (key == KEY_SUB && e->input.iteration > 1)
		e->input.iteration -= 5;
	else if (key >= KEY_THEME0 && key <= KEY_THEME1)
		e->input.theme = key - 18;
	else
		return ;
	ft_itoa_cust(e->input.iteration, &e->input.str[ITE]);
}

int				ft_dealkey(int key, void *param)
{
	mlx_clear_window(((ENV *)param)->mlxvar.mlx, ((ENV *)param)->mlxvar.win);
	if (key == KEY_ESC)
		return (ft_close_window((ENV *)param));
	ft_move_and_zoom((ENV *)param, key);
	ft_change_color((ENV *)param, key);
	ft_change_iter_or_theme((ENV *)param, key);
	if (key == KEY_PAUSE)
		((ENV *)param)->input.pause = ((ENV *)param)->input.pause ? 0 : 1;
	else if (key == KEY_RESET)
		ft_reset((ENV *)param);
	ft_itoa_cust(((ENV *)param)->input.blue, &((ENV *)param)->input.str[B]);
	ft_itoa_cust(((ENV *)param)->input.green, &((ENV *)param)->input.str[G]);
	ft_itoa_cust(((ENV *)param)->input.red, &((ENV *)param)->input.str[R]);
	ft_fractalize((ENV *)param);
	ft_display((ENV *)param);
	return (0);
}
