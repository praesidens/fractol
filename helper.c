/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 21:22:22 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/14 21:22:25 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel_to_image(t_fractol *f, int x, int y, int color)
{
	(void)color;
	if (x < WIN_W && f->y < WIN_H)
		f->img_data[x + y * f->line_len / 4] = color;
}
