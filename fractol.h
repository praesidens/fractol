/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:32:50 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/09 00:49:55 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <pthread.h>
# include <math.h>
# include <mlx.h>

# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_LEFT		123
# define KEY_PERIOD		47
# define KEY_COMMA		43
# define KEY_PLUS		24
# define KEY_MINUS		27
# define ESC			53
# define SCROLL_UP		5
# define SCROLL_DOWN	4
# define SPACE			49

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1

# define WIN_W			1200
# define WIN_H			800

# define WIN_X_CENTER	(WIN_W / 2)
# define WIN_Y_CENTER	(WIN_H / 2)

# define THREADS		8

# define P_THR_STEP 	(WIN_W / THREADS)

typedef struct			s_reim
{
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
}						t_reim;

typedef	struct			s_fractol
{
	int					type;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*img_data;
	int					endian;
	int					line_len;
	int					bpp;
	int					max_iter;
	double				c_r;
	double				c_i;
	double				n_r;
	double				n_i;
	double				o_r;
	double				o_i;
	double				p_r;
	double				p_i;
	double				zoom;
	int					color;
	int					win_x;
	int					win_y;
	double				x;
	double				y;
	double				c1;
	double				c2;
	double				c1_j;
	double				c2_j;
	int					max_y;
	double				temp;
	int					julia;
}						t_fractol;

/*
**	Init fractol
*/
void					init_mlx_fractol(t_fractol *fract);
void					init_right_type(t_fractol *fract);
/*
**	Find the right fractal function
*/
int						find_fractol_func(t_fractol *fract, char **av);
void					print_fract(t_fractol *fract);
/*
**	Mandelbrot fractal
*/
void					mandelbrot_threads(t_fractol *fract);
void					*mandelbrot_helper(void *storage);
void					mandelbrot(t_fractol *fract);
void					init_mandelbrot(t_fractol *fract);
/*
**	Julia fractal
*/
void					julia_threads(t_fractol *fract);
void					*julia_helper(void *storage);
void					julia(t_fractol *fract);
void					init_julia(t_fractol *fract);
/*
**	Sierpinski fractal
*/
void					init_sierpinski(t_fractol *fract);
void					sierpinski(t_fractol *fract);
/*
**	My own fractal
*/
void					init_myown(t_fractol *f);
void					myown_threads(t_fractol *fract);
void					*myown_helper(void *storage);
void					myown(t_fractol *f);
/*
**	Burning
*/
void					init_burning(t_fractol *f);
void					burning_threads(t_fractol *fract);
void					*burning_helper(void *storage);
void					burning(t_fractol *f);
/*
**	Burningship
*/
void					init_burningship(t_fractol *f);
void					burningship_threads(t_fractol *fract);
void					*burningship_helper(void *storage);
void					burningship(t_fractol *f);
/*
**	Burningship
*/
void					init_shuriken(t_fractol *f);
void					shuriken_threads(t_fractol *fract);
void					*shuriken_helper(void *storage);
void					shuriken(t_fractol *f);
/*
**	Basic bullshit
*/
void					put_pixel_to_image(t_fractol *f, int x, int y, int c);
int						main_hook(int keycode, t_fractol *f);
int						find_color_2(t_fractol *f, int i);
int						find_color_3(t_fractol *f, int i);
int						find_color_4(t_fractol *f, int i);
int						find_color_5(t_fractol *f, int i);
int						find_color_6(t_fractol *f, int i);
int						move_mouse_hook(int x, int y, t_fractol *fract);
int						scroll_hook(int scroll, int x, int y, t_fractol *fract);

#endif
