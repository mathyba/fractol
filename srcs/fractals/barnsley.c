/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuckens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:16:05 by emuckens          #+#    #+#             */
/*   Updated: 2018/06/25 18:07:13 by emuckens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		ft_barnsley(ENV *e, int row, int col)
{
	int					prob;
	static t_4fvect		f;
	static t_4fvect		tmp;

	if ((prob = rand() % 100) == 0)
		ft_4fvinit(&f, 0, 0.16 * tmp.y, 0);
	else if (prob < 85)
		ft_4fvinit(&f, 0.85 * tmp.x + 0.04 * tmp.y,
				-0.04 * tmp.x + 0.85 * tmp.y + 1.6, 0);
	else if (prob < 93)
		ft_4fvinit(&f, 0.2 * tmp.x - 0.26 * tmp.y,
				0.23 * tmp.x + 0.22 * tmp.y + 1.6, 0);
	else
		ft_4fvinit(&f, -0.15 * tmp.x + 0.28 * tmp.y,
				0.26 * tmp.x + 0.24 * tmp.y + 0.44, 0);
	ft_4fvinit(&tmp, f.x, f.y, 0);
	e->color = ft_getcolor(e, prob);
	col = f.x * e->zoom + e->offset.x;
	row = f.y * e->zoom + e->offset.y;
	if (col >= 0 && col < MENU_START && row >= 0 && row < WIN_H)
		ft_put_to_img(e, row, col, e->color);
	return (0);
}
