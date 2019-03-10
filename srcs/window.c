/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:44:07 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:06:11 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int	ft_initwin(ENV *e)
{
	if (!(e->mlxvar.mlx = mlx_init()))
		return (0);
	e->mlxvar.win = mlx_new_window(e->mlxvar.mlx, WIN_W, WIN_H, WIN_TITLE);
	if (!e->mlxvar.win)
		return (0);
	return (1);
}

int	ft_close_window(ENV *e)
{
	mlx_clear_window(e->mlxvar.mlx, e->mlxvar.win);
	mlx_destroy_window(e->mlxvar.mlx, e->mlxvar.win);
	exit(0);
}
