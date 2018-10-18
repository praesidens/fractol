/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:39:01 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/14 20:44:40 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_fractol	*fract;

	if (!(fract = (t_fractol*)malloc(sizeof(t_fractol))))
		return (EXIT_FAILURE);
	if (ac == 2)
	{
		init_mlx_fractol(fract);
		if (!(find_fractol_func(fract, av)))
			return (0);
		init_right_type(fract);
		mlx_key_hook(fract->win_ptr, main_hook, fract);
		mlx_mouse_hook(fract->win_ptr, scroll_hook, fract);
		mlx_hook(fract->win_ptr, 6, 1L << 6, move_mouse_hook, fract);
		mlx_loop(fract->mlx_ptr);
	}
	else
		ft_putendl("Usage: ./fractol {mandelbrot | julia |"
					" burning | burningship | my_own | shuriken}");
	return (0);
}

int		find_fractol_func(t_fractol *fract, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		fract->type = 1;
	else if (ft_strcmp(av[1], "julia") == 0)
		fract->type = 2;
	else if (ft_strcmp(av[1], "my_own") == 0)
		fract->type = 3;
	else if (ft_strcmp(av[1], "burning") == 0)
		fract->type = 4;
	else if (ft_strcmp(av[1], "burningship") == 0)
		fract->type = 5;
	else if (ft_strcmp(av[1], "shuriken") == 0)
		fract->type = 6;
	else
	{
		ft_putendl("Usage: ./fractol {mandelbrot | julia |"
					" burning | burningship | my_own }");
		return (0);
	}
	return (1);
}

void	init_right_type(t_fractol *fract)
{
	if (fract->type == 1)
		init_mandelbrot(fract);
	else if (fract->type == 2)
		init_julia(fract);
	else if (fract->type == 3)
		init_myown(fract);
	else if (fract->type == 4)
		init_burning(fract);
	else if (fract->type == 5)
		init_burningship(fract);
	else if (fract->type == 6)
		init_shuriken(fract);
	print_fract(fract);
}

void	print_fract(t_fractol *fract)
{
	if (fract->max_iter < 0)
		fract->max_iter = 0;
	if (fract->type == 1)
		mandelbrot_threads(fract);
	else if (fract->type == 2)
		julia_threads(fract);
	else if (fract->type == 3)
		myown_threads(fract);
	else if (fract->type == 4)
		burning_threads(fract);
	else if (fract->type == 5)
		burningship_threads(fract);
	else if (fract->type == 6)
		shuriken_threads(fract);
}

void	init_mlx_fractol(t_fractol *fract)
{
	fract->mlx_ptr = mlx_init();
	fract->win_ptr = mlx_new_window(fract->mlx_ptr, WIN_W, WIN_H, \
	"Fractol bsuprun");
	fract->img_ptr = mlx_new_image(fract->mlx_ptr, WIN_W, WIN_H);
	fract->img_data = (int*)mlx_get_data_addr(fract->img_ptr, \
	&fract->bpp, &fract->line_len, &fract->endian);
}
