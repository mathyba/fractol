/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:48:01 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 17:31:09 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_block(ENV *e, int it)
{
	int clr;

	(void)it;
	clr = e->input.red + (e->input.green << 8) + (e->input.blue << 16);
	return (clr);
}

static int		ft_strippy(ENV *e, int it)
{
	int clr;

	clr = it * (e->input.red + (e->input.green << 8) + (e->input.blue << 16));
	return (clr);
}

int				ft_getcolor(ENV *e, int iter)
{
	static int	(*color[2])(ENV *e, int iter) = {&ft_block, &ft_strippy};

	if ((iter == e->input.iteration && !e->input.color_inv)
			|| (iter < e->input.iteration && e->input.color_inv))
		return (0);
	else
		return (color[e->input.theme](e, iter));
}
