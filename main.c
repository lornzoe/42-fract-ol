/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 00:06:26 by lyanga            #+#    #+#             */
/*   Updated: 2025/09/26 23:16:15 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else
	{
		ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}


int main(int argc, char **argv) {
	t_fractal	*fractal;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia", 1);
		return (0);
	}
	fractal = malloc(sizeof(t_fractal));

	init_fractal(fractal);
	init_mlx(fractal);

	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	
	return 0;
}