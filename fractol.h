/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 23:04:32 by lyanga            #+#    #+#             */
/*   Updated: 2025/10/01 18:21:42 by lyanga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <math.h>
#include <X11/X.h>


# define SIZE 900

# ifdef __APPLE__
#  define CLOSE_WINDOW 17
# else
#  define CLOSE_WINDOW 33
# endif

// key codes
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define PLUS 61
# define MINUS 45

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
double		generate_random_c(void);
void		change_iterations(t_fractal *fractal, int key_code);

void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);

// julia.c
void		calculate_julia(t_fractal *fractal);

// burning_ship.c
void		calculate_burning_ship(t_fractal *fractal);

// main.c
int			draw_fractal(t_fractal *fractal, char *query);

// mouse_and_keys.c
int			close_fractol(t_fractal *fractal);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

// draw.c
void		draw_mandelbrot(t_fractal *fractal);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

#endif