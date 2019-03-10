/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractalize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:08:54 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:00:49 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_apply_fractal(void *arg)
{
	int			row;
	int			col;
	static int	(*fractal[7])(ENV *e, int row, int col) = {
		&ft_mandelbrot,
		&ft_julia,
		&ft_barnsley,
		&ft_burningship,
		&ft_tricorn,
		&ft_spiral,
		&ft_geonerd};

	row = ((ENV *)arg)->index;
	while (row < WIN_H)
	{
		col = -1;
		while (++col < MENU_START)
			fractal[((ENV *)arg)->input.fractal]((ENV *)arg, row, col);
		row += NB_THREADS;
	}
	pthread_exit(NULL);
}

void	ft_fractalize(ENV *e)
{
	e->index = 0;
	ft_bzero(e->mlxvar.ptr, WIN_H * WIN_W * 4);
	while (e->index < NB_THREADS)
	{
		if (pthread_create(&e->thr[e->index], NULL, ft_apply_fractal, e) == -1)
			ft_display_error("failed creating thread\n");
		if (pthread_join(e->thr[e->index], NULL))
			ft_display_error("failed joining thread\n");
		++e->index;
	}
}
