/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 00:06:26 by lyanga            #+#    #+#             */
/*   Updated: 2025/10/05 14:48:22 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	print_usage(int usage)
{
	if (usage)
		ft_putendl_fd("Usage: ./fractol <fractal> [parameters]", 2);
	ft_putendl_fd("Available fractals:", 2);
	ft_putendl_fd("	- mandelbrot (./fractol mandelbrot)", 2);
	ft_putendl_fd("	- julia (./fractol julia <real c> <imag. c>)", 2);
	ft_putendl_fd("		- e.g. ./fractol julia 0.25 0.75", 2);
	ft_putendl_fd("	- burning_ship (./fractol burning_ship)", 2);
	return (0);
}

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandelbrot", 11) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(query, "julia", 6) == 0)
		draw_julia(fractal);
	else if (ft_strncmp(query, "burning_ship", 13) == 0)
		draw_burning_ship(fractal);
	else
	{
		print_usage(0);
		close_fractol(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

static int	validate_julia(char *val1, char *val2)
{
	if (!(check_float(val1) && check_float(val2)))
	{
		ft_putendl_fd("Error: Invalid parameter value(s) provided.", 2);
		return (0);
	}
	return (1);
}

static int	validate_argv(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0
		|| ft_strncmp(argv[1], "burning_ship", 13) == 0)
	{
		if (argc != 2)
		{
			if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
				ft_putendl_fd("Error: 'mandelbrot' takes no parameters.", 2);
			else
				ft_putendl_fd("Error: 'burning_ship' takes no parameters.", 2);
			return (0);
		}
		return (1);
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
		{
			ft_putendl_fd("Error: 'julia' takes 2 params: <real c> <imag. c>.",
				2);
			return (0);
		}
		return (validate_julia(argv[2], argv[3]));
	}
	return (print_usage(0));
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
		return (print_usage(1));
	if (!validate_argv(argc, argv))
		return (0);
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractal->cx = ft_atod(argv[2]);
		fractal->cy = ft_atod(argv[3]);
	}
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, CLOSE_WINDOW, 0, close_fractol, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
