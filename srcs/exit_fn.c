/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:38:14 by amelikia          #+#    #+#             */
/*   Updated: 2019/04/23 17:04:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_plus(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->x *= 1.3;
			fdf->xyz_stock[i][j]->y *= 1.3;
			fdf->xyz_stock[i][j]->z *= 1.1;
			j++;
		}
		i++;
	}
}

void	zoom_minus(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->x /= 1.3;
			fdf->xyz_stock[i][j]->y /= 1.3;
			fdf->xyz_stock[i][j]->z /= 1.1;
			j++;
		}
		i++;
	}
}

void	apl_plus(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->z *= 1.1;
			j++;
		}
		i++;
	}
}

void	apl_minus(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j]->z /= 1.1;
			j++;
		}
		i++;
	}
}

int		exit_fn(int key, t_fdf *fdf, int i)
{
	(key == 27) ? zoom_minus(fdf) : (i = 0);
	(key == 24) ? zoom_plus(fdf) : (i = 0);
	(key == 25) ? apl_plus(fdf) : (i = 0);
	(key == 29) ? apl_minus(fdf) : (i = 0);
	if (key == 42 || key == 126 || key == 125 || key == 123 || \
		key == 124 || key == 27 || key == 25 || key == 24 || key == 29)
		mlx_clear_window(fdf->mlx, fdf->win);
	(key == 53) ? exit(1) : (i = 0);
	(key == 126) ? fdf->angle->x += 0.1 : (i = 0);
	(key == 126) ? fdf->angle->y += 0.1 : (i = 0);
	(key == 125 || key == 123) ? fdf->angle->x -= 0.1 : (i = 0);
	(key == 125 || key == 124) ? fdf->angle->y -= 0.1 : (i = 0);
	if (key == 126 || key == 125 || key == 123 || key == 124 || \
		key == 27 || key == 25 || key == 24 || key == 29)
	{
		make_modified(fdf);
		print_figure(fdf);
	}
	return (0);
}
