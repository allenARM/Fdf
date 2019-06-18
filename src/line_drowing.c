/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drowing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:37:15 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/18 14:34:38 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_low_assign_value(t_point **diff, t_point **point, \
							t_point *first, t_point *second)
{
	int		yi;

	yi = 0;
	(*diff)->x = second->x - first->x;
	(*diff)->y = second->y - first->y;
	(*diff)->z = (second->z > first->z) ? (second->z - first->z) : \
											(first->z - second->z);
	yi = 0;
	((*diff)->y < 0) ? (yi -= 1) : (yi += 1);
	((*diff)->y < 0) ? ((*diff)->y = -(*diff)->y) : (yi += 0);
	(*point)->z = 2 * (*diff)->y - (*diff)->x;
	(*point)->y = first->y;
	(*point)->x = first->x - 1;
	return (yi);
}

void	print_low(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point			*diff;
	t_point			*point;
	int				yi;
	double			color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	yi = print_low_assign_value(&diff, &point, first, second);
	color_increment = diff->z / (second->y - point->y);
	while (++point->x < second->x)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, (int)point->x, (int)point->y, \
					minimum_altitude);
		(point->z > 0) ? (point->y = point->y + yi) : (minimum_altitude += 0);
		(point->z > 0) ? (point->z = point->z - 2 * diff->x) : \
					(minimum_altitude += 0);
		minimum_altitude += color_increment * 200;
		point->z = point->z + 2 * diff->y;
	}
	free(diff);
	free(point);
}

int		print_high_assign_value(t_point **diff, t_point **point, \
								t_point *first, t_point *second)
{
	int		xi;

	xi = 0;
	(*diff)->x = second->x - first->x;
	(*diff)->y = second->y - first->y;
	(*diff)->z = (second->z > first->z) ? (second->z - first->z) : \
											(first->z - second->z);
	xi = 0;
	((*diff)->x < 0) ? (xi -= 1) : (xi = 1);
	((*diff)->x < 0) ? ((*diff)->x = -(*diff)->x) : (xi += 0);
	(*point)->z = 2 * (*diff)->x - (*diff)->y;
	(*point)->y = first->y - 1;
	(*point)->x = first->x;
	return (xi);
}

void	print_high(t_fdf *fdf, t_point *first, \
					t_point *second, int minimum_altitude)
{
	t_point			*diff;
	t_point			*point;
	int				xi;
	double			color_increment;

	diff = (t_point *)malloc(sizeof(t_point));
	point = (t_point *)malloc(sizeof(t_point));
	xi = print_high_assign_value(&diff, &point, first, second);
	color_increment = diff->z / (second->y - point->y);
	while (++point->y < second->y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, (int)point->x, (int)point->y, \
						minimum_altitude);
		(point->z > 0) ? (point->x = point->x + xi) : (minimum_altitude += 0);
		(point->z > 0) ? (point->z = point->z - 2 * diff->y) : \
						(minimum_altitude += 0);
		minimum_altitude += color_increment * 200;
		point->z = point->z + 2 * diff->x;
	}
	free(diff);
	free(point);
}

void	printline(t_fdf *fdf)
{
	int		minimum_altitude;

	minimum_altitude = (fdf->first->z > fdf->second->z ? \
						fdf->second->z : fdf->first->z);
	if (ft_abs(fdf->second->y - fdf->first->y) < \
		ft_abs(fdf->second->x - fdf->first->x))
	{
		if (fdf->first->x > fdf->second->x)
			print_low(fdf, fdf->second, fdf->first, minimum_altitude + 9056567);
		else
			print_low(fdf, fdf->first, fdf->second, minimum_altitude + 9056567);
	}
	else
	{
		if (fdf->first->y > fdf->second->y)
			print_high(fdf, fdf->second, fdf->first,\
				minimum_altitude + 9056567);
		else
			print_high(fdf, fdf->first, fdf->second,\
				minimum_altitude + 9056567);
	}
}
