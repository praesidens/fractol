/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 20:44:25 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/14 20:44:29 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main_hook(int keycode, t_fractol *f)
{
	if (keycode == ESC)
		exit(1);
	else if (keycode == KEY_PLUS)
		f->max_iter += 20;
	else if (keycode == KEY_MINUS && f->max_iter > 2)
		f->max_iter -= 20;
	else if (keycode == KEY_RIGHT)
		f->c1 -= 0.1 / f->zoom;
	else if (keycode == KEY_LEFT)
		f->c1 += 0.1 / f->zoom;
	else if (keycode == KEY_UP)
		f->c2 += 0.1 / f->zoom;
	else if (keycode == KEY_DOWN)
		f->c2 -= 0.1 / f->zoom;
	else if (keycode == SPACE && f->julia == 1)
		f->julia = 0;
	else if (keycode == SPACE && !f->julia)
		f->julia = 1;
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	print_fract(f);
	return (0);
}

int			scroll_hook(int scroll, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (scroll == 4)
	{
		f->zoom *= 1.2;
	}
	else if (scroll == 5 && f->zoom > 0.1)
	{
		f->zoom /= 1.2;
	}
	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	print_fract(f);
	return (0);
}

int			move_mouse_hook(int x, int y, t_fractol *fract)
{
	if (fract->julia == 1)
	{
		fract->c1_j = x;
		fract->c2_j = y;
		mlx_clear_window(fract->mlx_ptr, fract->win_ptr);
		print_fract(fract);
	}
	return (0);
}
