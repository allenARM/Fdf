/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drowing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:37:15 by amelikia          #+#    #+#             */
/*   Updated: 2019/04/24 12:54:49 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_low(t_fdf *fdf, t_double_point *first, t_double_point *second)
{
	int		color;
	double	diffx;
	double	diffy;
	double	yi;
	double	d;
	double	y;
	double	x;

	color = 98765;
	diffx = second->x - first->x;
	diffy = second->y - first->y;
	yi = 0;
	(diffy < 0) ? (yi -= 1) : (yi += 1);
	(diffy < 0) ? (diffy = -diffy) : (yi += 0);
	d = 2 * diffy - diffx;
	y = first->y;
	x = first->x - 1;
	while (++x != second->x)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * diffx;
		}
		color -= 280;
		d = d + 2 * diffy;
	}
}

void	print_high(t_fdf *fdf, t_double_point *first, t_double_point *second)
{
	int		color;
	double	diffx;
	double	diffy;
	double	xi;
	double	d;
	double	y;
	double	x;

	color = 98765;
	diffx = second->x - first->x;
	diffy = second->y - first->y;
	xi = 0;
	(diffx < 0) ? (xi -= 1) : (xi = 1);
	(diffx < 0) ? (diffx = -diffx) : (xi += 0);
	d = 2 * diffx - diffy;
	y = first->y - 1;
	x = first->x;
	while (++y != second->y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * diffy;
		}
		color -= 280;
		d = d + 2 * diffx;
	}
}

void	printline(t_fdf *fdf)
{
	if (ft_abs(fdf->second->y - fdf->first->y) < ft_abs(fdf->second->x - fdf->first->x))
	{
		if (fdf->first->x > fdf->second->x)
			print_low(fdf, fdf->second, fdf->first);
		else
			print_low(fdf, fdf->first, fdf->second);
	}
	else
	{
		if (fdf->first->y > fdf->second->y)
			print_high(fdf, fdf->second, fdf->first);
		else
			print_high(fdf, fdf->first, fdf->second);
	}
}
