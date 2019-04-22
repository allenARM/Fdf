/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:38:14 by amelikia          #+#    #+#             */
/*   Updated: 2019/04/22 14:06:52 by amelikia         ###   ########.fr       */
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

int	exit_fn(int key, t_fdf *fdf)
{
	if (key == 53) //esc
		exit(1);
	if (key == 42) //над энтером
		mlx_clear_window(fdf->mlx, fdf->win);
	if (key == 126) //стрелка вверх
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->anglex = fdf->anglex + 0.1;
		fdf->angley = fdf->angley + 0.1;
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 125) //стрелка вниз
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->anglex = fdf->anglex - 0.1;
		fdf->angley = fdf->angley - 0.1;
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 123) //стрелка влево
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->anglex = fdf->anglex - 0.1;
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 124) //стрелка вправо
	{
		mlx_clear_window(fdf->mlx, fdf->win);
		fdf->angley = fdf->angley - 0.1;
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 27) // МИНУС
	{
		zoom_minus(fdf);
		mlx_clear_window(fdf->mlx, fdf->win);
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 24) // ПЛЮС
	{
		zoom_plus(fdf);
		mlx_clear_window(fdf->mlx, fdf->win);
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 25) // 9
	{
		apl_plus(fdf);
		mlx_clear_window(fdf->mlx, fdf->win);
		make_modified(fdf);
		print_figure(fdf);
	}
	if (key == 29) // 0
	{
		apl_minus(fdf);
		mlx_clear_window(fdf->mlx, fdf->win);
		make_modified(fdf);
		print_figure(fdf);
	}
	return (0);
}