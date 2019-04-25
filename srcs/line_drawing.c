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

void	print_low(t_fdf *fdf, t_double_point *first, \
					t_double_point *second, int color)
{
	t_double_point	*diff;
	t_double_point	*point;
	double			yi;
	double			d;

	diff = (t_double_point *)malloc(sizeof(t_double_point));
	point = (t_double_point *)malloc(sizeof(t_double_point));
	diff->x = second->x - first->x;
	diff->y = second->y - first->y;
	yi = 0;
	(diff->y < 0) ? (yi -= 1) : (yi += 1);
	(diff->y < 0) ? (diff->y = -diff->y) : (yi += 0);
	d = 2 * diff->y - diff->x;
	point->y = first->y;
	point->x = first->x - 1;
	while (++point->x != second->x)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, point->x, point->y, color);
		(d > 0) ? (point->y = point->y + yi) : (color += 0);
		(d > 0) ? (d = d - 2 * diff->x) : (color += 0);
		color -= 280;
		d = d + 2 * diff->y;
	}
}

void	print_high(t_fdf *fdf, t_double_point *first, \
					t_double_point *second, int color)
{
	t_double_point	*diff;
	t_double_point	*point;
	double			xi;
	double			d;

	diff = (t_double_point *)malloc(sizeof(t_double_point));
	point = (t_double_point *)malloc(sizeof(t_double_point));
	diff->x = second->x - first->x;
	diff->y = second->y - first->y;
	xi = 0;
	(diff->x < 0) ? (xi -= 1) : (xi = 1);
	(diff->x < 0) ? (diff->x = -diff->x) : (xi += 0);
	d = 2 * diff->x - diff->y;
	point->y = first->y - 1;
	point->x = first->x;
	while (++point->y != second->y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, point->x, point->y, color);
		(d > 0) ? (point->x = point->x + xi) : (color += 0);
		(d > 0) ? (d = d - 2 * diff->y) : (color += 0);
		color -= 280;
		d = d + 2 * diff->x;
	}
}

void	printline(t_fdf *fdf)
{
	if (ft_abs(fdf->second->y - fdf->first->y) < \
		ft_abs(fdf->second->x - fdf->first->x))
	{
		if (fdf->first->x > fdf->second->x)
			print_low(fdf, fdf->second, fdf->first, 98765);
		else
			print_low(fdf, fdf->first, fdf->second, 98765);
	}
	else
	{
		if (fdf->first->y > fdf->second->y)
			print_high(fdf, fdf->second, fdf->first, 98765);
		else
			print_high(fdf, fdf->first, fdf->second, 98765);
	}
}
