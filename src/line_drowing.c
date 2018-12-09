/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drowing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:37:15 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/09 15:48:21 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printLOW(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int diffx;
	int diffy;
	int yi;
	int d;
	int y;
	int x;

	x1 > x2 ? (diffx = x1 - x2) : (diffx = x2 - x1);
	diffy = y2 - y1;
	yi = 1;
	if (diffy < 0)
	{
		yi = -1;
		diffy = -diffy;
	}
	d = 2 * diffy - diffx;
	y = y1;
	x = x1;
	while (x != x2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
		if (d > 0)
		{
			y = y + yi;
			d = d - 2 * diffx;
		}
		x++;
		d = d + 2 * diffy;
	}
}

void	printHIGH(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int diffx;
	int diffy;
	int xi;
	int d;
	int y;
	int x;

	diffx = x2 - x1;
	y1 > y2 ? (diffy = y1 - y2) : (diffy = y2 - y1);
	xi = 1;
	if (diffx < 0)
	{
		xi = -1;
		diffx = -diffx;
	}
	d = 2 * diffx - diffy;
	y = y1;
	x = x1;
	while (y != y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
		if (d > 0)
		{
			x = x + xi;
			d = d - 2 * diffy;
		}
		y++;
		d = d + 2 * diffx;
	}
}

void	printline(t_fdf *fdf)
{
	if (ft_abs(fdf->y2 - fdf->y1) < ft_abs(fdf->x2 - fdf->x1))
	{
		if (fdf->x1 > fdf->x2)
			printLOW(fdf, fdf->x2, fdf->y2, fdf->x1, fdf->y1);
		else
			printLOW(fdf, fdf->x1, fdf->y1, fdf->x2, fdf->y2);
	}
	else
	{
		if (fdf->y1 > fdf->y2)
			printHIGH(fdf, fdf->x2, fdf->y2, fdf->x1, fdf->y1);
		else
			printHIGH(fdf, fdf->x1, fdf->y1, fdf->x2, fdf->y2);
	}
	fdf->x1 = 0;
	fdf->x2 = 0;
	fdf->y1 = 0;
	fdf->y2 = 0;
}

int		mouse_release(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1 && fdf->x1 == 0)
	{
		ft_printf("x: %d y: %d\n", x, y);
		mlx_pixel_put(fdf->mlx, fdf->win, x - 2, y - 2, 0x8470ff);
		mlx_pixel_put(fdf->mlx, fdf->win, x - 1, y - 1, 0x8470ff);
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0x8470ff);
		mlx_pixel_put(fdf->mlx, fdf->win, x + 2, y + 2, 0x8470ff);
		mlx_pixel_put(fdf->mlx, fdf->win, x + 1, y + 1, 0x8470ff);
		fdf->x1 = x;
		fdf->y1 = y;
	}
	else if (button == 1 && fdf->x1 != 0)
	{
		ft_printf("x: %d y: %d\n", x, y);
		mlx_pixel_put(fdf->mlx, fdf->win, x - 2, y - 2, 0xff1493);
		mlx_pixel_put(fdf->mlx, fdf->win, x - 1, y - 1, 0xff1493);
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xff1493);
		mlx_pixel_put(fdf->mlx, fdf->win, x + 2, y + 2, 0xff1493);
		mlx_pixel_put(fdf->mlx, fdf->win, x + 1, y + 1, 0xff1493);
		fdf->x2 = x;
		fdf->y2 = y;
	}
	if (fdf->x1 > 0 && fdf->x2 > 0)
		printline(fdf);
	return (0);
}
