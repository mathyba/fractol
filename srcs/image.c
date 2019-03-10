/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:36:23 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:02:01 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_fill_bckgrnd(ENV *e, int end_row, int option)
{
	int row;
	int col;
	int end;

	end = MENU_END - MENU_START - 20;
	if (option == 1)
	{
		col = -1;
		while (++col < end)
		{
			row = -1;
			while (++row < end_row)
				ft_putcoord_to_img(e, row, col, COL_BCKGRND);
		}
		return ;
	}
	col = MENU_START + 20;
	while (++col < WIN_W)
	{
		row = -1;
		while (++row < end_row)
			ft_put_to_img(e, row, col, COL_BCKGRND);
	}
}

int				ft_getimg(ENV *e)
{
	e->mlxvar.img = mlx_new_image(e->mlxvar.mlx, WIN_W, WIN_H);
	e->mlxvar.coordimg = mlx_new_image(e->mlxvar.mlx, 300, 80);
	e->mlxvar.ptr = mlx_get_data_addr(e->mlxvar.img, &e->mlxvar.bpp,
			&e->mlxvar.size, &e->mlxvar.endian);
	e->mlxvar.coordptr = mlx_get_data_addr(e->mlxvar.coordimg, &e->mlxvar.bpp,
			&e->mlxvar.size, &e->mlxvar.endian);
	return (1);
}

void			ft_putcoord_to_img(ENV *e, size_t row, size_t col, int color)
{
	int		offset;

	offset = (row * 300 + col) << 2;
	*(int *)(e->mlxvar.coordptr + offset) = color;
}

void			ft_put_to_img(ENV *e, size_t row, size_t col, int color)
{
	int		offset;

	offset = (row * WIN_W + col) << 2;
	*(int *)(e->mlxvar.ptr + offset) = color;
}
