/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:16:12 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/26 12:08:34 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "X.h"

static void		ft_display_usage(char *exe, int option)
{
	if (option == 0)
		ft_printf("\n{DRED}Please enter a valid fractal name!{EOC}\n", exe);
	else
		ft_printf("\n{DRED}Usage: %s [fractal name]{EOC}\n", exe);
	ft_printf("{CYAN}}Available fractals:\n\n");
	ft_printf("\tmandelbrot\n\tjulia\n\tbarnsley\n\tburningship\n\ttricorn\n");
	ft_printf("\tspiral\n\tgeonerd\n\n{EOC}");
}

static void		ft_handle_hooks(ENV *e)
{
	mlx_hook(e->mlxvar.win, MotionNotify, PointerMotionMask, &ft_motionhook, e);
	mlx_hook(e->mlxvar.win, KeyPress, KeyPressMask, &ft_dealkey, e);
	mlx_mouse_hook(e->mlxvar.win, &ft_dealbutton, e);
}

int				main(int argc, char **argv)
{
	static ENV e;

	if (argc == 2)
	{
		if (!ft_initwin(&e) || !ft_getimg(&e))
			ft_display_error("failed setting up graphic environment");
		ft_getenv(&e);
		if ((ft_select_fractal(&e, 0, argv[1])))
		{
			ft_fractalize(&e);
			ft_display(&e);
			ft_handle_hooks(&e);
			mlx_loop(e.mlxvar.mlx);
			return (0);
		}
		ft_display_usage(argv[0], 0);
		ft_close_window(&e);
		return (0);
	}
	ft_display_usage(argv[0], 1);
	return (0);
}
