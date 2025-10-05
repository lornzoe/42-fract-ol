/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 23:14:05 by lyanga            #+#    #+#             */
/*   Updated: 2025/10/05 15:34:01 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = (fractal->zx * fractal->zx) - (fractal->zy * fractal->zy)
			+ fractal->cx;
		fractal->zy = 2.0 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * (i
					% 255)));
}
