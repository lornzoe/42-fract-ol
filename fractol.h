/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:04:32 by lyanga            #+#    #+#             */
/*   Updated: 2025/09/27 08:49:15 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

# define SIZE 420

// key codes
# define ESC 65307 //53
# define UP 65362 //126
# define DOWN 65364 //125
# define LEFT 65361 //123
# define RIGHT 65363 //124
# define R 114 //15
# define C 99 //8
# define H 104 //52 
# define J 106 //38
# define P 112 //35
# define M 109 //46

// mouse codes
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

// utils.c
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_fractal(t_fractal *fractal);
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);

void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal, char *query);

// mouse_and_keys.c
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

// draw.c
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

#endif