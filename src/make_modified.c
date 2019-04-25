/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_modified.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:39:03 by amelikia          #+#    #+#             */
/*   Updated: 2019/04/24 16:15:44 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_modified(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	fdf->xyz_modif = malloc(sizeof(t_point*) * (fdf->height + 5));
	fdf->xyz_modif[fdf->height] = NULL;
	while (i < fdf->height)
	{
		fdf->xyz_modif[i] = malloc(sizeof(t_point) * (fdf->width + 5));
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_modif[i][j] = malloc(sizeof(t_point));
			fdf->xyz_modif[i][j]->x = 400 + ((fdf->xyz_stock[i][j]->x -\
				fdf->xyz_stock[i][j]->y) * cos(fdf->angle->x));
			fdf->xyz_modif[i][j]->y = 150 + (((fdf->xyz_stock[i][j]->x +\
				fdf->xyz_stock[i][j]->y) * sin(fdf->angle->y))\
				- fdf->xyz_stock[i][j]->z);
			j++;
		}
		i++;
	}
}
