/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:35:32 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/07 06:34:19 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_int_len(int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
