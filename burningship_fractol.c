/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_fractol.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 20:44:09 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/14 20:44:11 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_burningship(t_fractol *f)
{
	f->max_iter = 20;
	f->zoom = 0.4;
	f->c1 = -0.5;
	f->c2 = 0;
}

void		burningship_threads(t_fractol *fract)
{
	t_fractol		*storage;
	pthread_t		*threads;
	int				j;

	storage = (t_fractol *)malloc(sizeof(t_fractol) * THREADS);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * THREADS);
	j = 0;
	while (j < THREADS)
	{
		ft_memcpy((void*)&storage[j], (void*)fract, sizeof(t_fractol));
		storage[j].y = P_THR_STEP * j;
		storage[j].max_y = P_THR_STEP * (j + 1);
		j++;
	}
	j = 0;
	while (++j <= THREADS)
		pthread_create(&threads[j - 1], NULL, \
						burningship_helper, &storage[j - 1]);
	while (j--)
		pthread_join(threads[j], NULL);
	free(storage);
	free(threads);
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, \
							fract->img_ptr, 0, 0);
}

void		*burningship_helper(void *storage)
{
	int			y;
	t_fractol	*fct_ptr;

	fct_ptr = (t_fractol *)storage;
	fct_ptr->x = -1;
	y = fct_ptr->y;
	while (++(fct_ptr->x) < WIN_W)
	{
		fct_ptr->y = y;
		while (fct_ptr->y < fct_ptr->max_y)
		{
			burningship(fct_ptr);
			fct_ptr->y++;
		}
	}
	return (storage);
}

void		burningship(t_fractol *f)
{
	int		i;

	f->n_r = 0;
	f->n_i = 0;
	f->o_r = 0;
	f->o_i = 0;
	i = 0;
	f->p_r = 1.5 * (f->x - WIN_W / 2) / (0.5 * f->zoom * WIN_W) + f->c1;
	f->p_i = (f->y - WIN_H / 2) / (0.5 * f->zoom * WIN_H) + f->c2;
	while (i < f->max_iter)
	{
		f->o_r = fabs(f->n_r);
		f->o_i = fabs(f->n_i);
		f->n_r = f->o_r * f->o_r - f->o_i * f->o_i + f->p_r;
		f->n_i = 2 * f->o_r * f->o_i + f->p_i;
		i++;
		if ((f->n_r * f->n_r + f->n_i * f->n_i) >= 4)
			break ;
	}
	if (i < f->max_iter)
		put_pixel_to_image(f, f->x, f->y, find_color_2(f, i));
	else
		put_pixel_to_image(f, f->x, f->y, 0x000000);
}
