/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 20:46:17 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/14 20:46:18 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_sierpinski(t_fractol *fract)
{
	fract->x = -1;
	fract->y = -1;
	fract->zoom = 1;
	fract->c1 = 0;
	fract->c2 = 0;
}

void		sierpinski(t_fractol *fract)
{
	while (++fract->y < WIN_H)
	{
		fract->x = -1;
		while (++fract->x < WIN_W)
		{
			if ((int)fract->x & (int)fract->y)
				put_pixel_to_image(fract, fract->x + fract->c1, \
									fract->y + fract->c2, 0xFFFFFF);
			else
				put_pixel_to_image(fract, fract->x + fract->c1, \
				fract->y + fract->c2, (int)fract->x % 256);
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, \
							fract->img_ptr, 0, 0);
}
