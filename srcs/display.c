/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:25:06 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/26 11:46:15 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_display_bckgrnd(ENV *e, int start)
{
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 10);
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 95);
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 180);
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 265);
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 350);
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 360);
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.coordimg,
			start, 750);
}

static void		ft_display_input(ENV *e)
{
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 880, 40, 0xFFFFFF,
			e->input.str[X]);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 930, 40, 0xFFFFFF, " : ");
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 980, 40, 0xFFFFFF,
			e->input.str[Y]);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 935, 220, 0xFFFFFF,
			e->input.str[ITE]);
}

static void		ft_display_colorsndir(ENV *e)
{
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 860, 270, 0xFF0000, R1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 870, 270, 0xFFFFFF, R2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 860, 290, 0x00FF00, G1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 870, 290, 0xFFFFFF, G2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 860, 310, 0x0000FF, B1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 870, 310, 0xFFFFFF, B2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 855, 110, 0xFFFFFF, M1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 940, 110, 0xFFFFFF, M2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 970, 105, 0xFFFFFF, "^");
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1020, 115, 0xFFFFFF, "v");
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1000, 270, 0xFF0000,
			e->input.str[R]);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1000, 290, 0x00FF00,
			e->input.str[G]);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1000, 310, 0x0000FF,
			e->input.str[B]);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 840, 360, 0xFFFFFF, C1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 840, 385, 0xFFFFFF, C2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 840, 410, 0xFFFFFF, C3);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1030, 360,
			e->input.theme == BLOCK ? COL_SELECT : 0xFFFFFF, "[1]");
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1030, 385,
			e->input.theme == STRIPPY ? COL_SELECT : 0xFFFFFF, "[2]");
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1030, 410,
			e->input.color_inv ? COL_SELECT : 0xFFFFFF, "[C]");
}

void			ft_display_menu(ENV *e)
{
	ft_display_bckgrnd(e, MENU_START + 10);
	ft_display_input(e);
	ft_display_colorsndir(e);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 865, 200, 0xFFFFFF, I1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 855, 140, 0xFFFFFF, Z1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 925, 140, 0xFFFFFF, Z2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 840, 765, 0xFFFFFF, RS);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1030, 765, 0xFFFFFF, "[~]");
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 900, 470, e->clr[MAN], F1);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 925, 510, e->clr[JUL], F2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1040, 510, COL_SELECT, P1);
	if (e->input.pause && e->input.fractal == JUL)
		mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1050, 510, COL_SELECT, P2);
	else
		mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1050, 510, 0xFFFFFF, P2);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 880, 550, e->clr[BAR], F3);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 892, 590, e->clr[BUR], F4);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 920, 630, e->clr[TRI], F5);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 925, 670, e->clr[SPI], F6);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 915, 710, e->clr[GEO], F7);
	mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1040, 710, COL_SELECT, P1);
	if (e->input.pause && e->input.fractal == GEO)
		mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1050, 710, COL_SELECT, P2);
	else
		mlx_string_put(e->mlxvar.mlx, e->mlxvar.win, 1050, 710, 0xFFFFFF, P2);
}

void			ft_display(ENV *e)
{
	mlx_put_image_to_window(e->mlxvar.mlx, e->mlxvar.win, e->mlxvar.img, 0, 0);
	ft_display_menu(e);
}
