/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 20:44:16 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/14 20:44:17 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_color_2(t_fractol *f, int i)
{
	double	c;
	int		r;
	int		g;
	int		b;

	c = (double)i / (double)f->max_iter;
	r = (int)(9 * (1 - c) * c * c * c * 255);
	g = (int)(15 * (1 - c) * (1 - c) * c * c * 255);
	b = (int)(8.5 * (1 - c) * (1 - c) * (1 - c) * c * 255);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int		find_color_3(t_fractol *f, int i)
{
	double	c;
	int		r;
	int		g;
	int		b;

	c = (double)i / (double)f->max_iter;
	g = (int)(9 * (1 - c) * c * c * c * 255);
	b = (int)(15 * (1 - c) * (1 - c) * c * c * 255);
	r = (int)(8.5 * (1 - c) * (1 - c) * (1 - c) * c * 255);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int		find_color_4(t_fractol *f, int i)
{
	double	c;
	int		r;
	int		g;
	int		b;

	c = (double)i / (double)f->max_iter;
	g = (int)(9 * (1 - c) * c * c * c * 255);
	r = (int)(15 * (1 - c) * (1 - c) * c * c * 255);
	b = (int)(8.5 * (1 - c) * (1 - c) * (1 - c) * c * 255);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int		find_color_5(t_fractol *f, int i)
{
	double	c;
	int		r;
	int		g;
	int		b;

	c = (double)i / (double)f->max_iter;
	r = (int)(9 * (1 - c) * c * c * c * 255);
	b = (int)(15 * (1 - c) * (1 - c) * c * c * 255);
	g = (int)(8.5 * (1 - c) * (1 - c) * (1 - c) * c * 255);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int		find_color_6(t_fractol *f, int i)
{
	double	c;
	int		r;
	int		g;
	int		b;

	c = (double)i / (double)f->max_iter;
	b = (int)(9 * (1 - c) * c * c * c * 255);
	g = (int)(15 * (1 - c) * (1 - c) * c * c * 255);
	r = (int)(8.5 * (1 - c) * (1 - c) * (1 - c) * c * 255);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
