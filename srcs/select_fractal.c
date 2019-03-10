/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:21:54 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:04:04 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_select_fractal(ENV *e, int y, char *arg)
{
	if (ft_strequ(arg, "mandelbrot") || (y >= 455 && y < 505))
		e->input.fractal = MAN;
	else if (ft_strequ(arg, "julia") || (y >= 505 && y < 545))
		e->input.fractal = JUL;
	else if (ft_strequ(arg, "barnsley") || (y >= 545 && y < 585))
		e->input.fractal = BAR;
	else if (ft_strequ(arg, "burningship") || (y >= 585 && y < 625))
		e->input.fractal = BUR;
	else if (ft_strequ(arg, "tricorn") || (y >= 625 && y < 665))
		e->input.fractal = TRI;
	else if (ft_strequ(arg, "spiral") || (y >= 665 && y < 705))
		e->input.fractal = SPI;
	else if (ft_strequ(arg, "geonerd") || (y >= 705 && y < 745))
		e->input.fractal = GEO;
	else
		return (0);
	ft_reset(e);
	return (1);
}
