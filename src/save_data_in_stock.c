/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data_in_stock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:33:11 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/17 19:20:47 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_data_in_stock(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	fdf->xyz_stock = malloc(sizeof(t_point*) * fdf->height);
	fdf->xyz_stock[fdf->height] = NULL;
	while (i < fdf->height)
	{
		fdf->xyz_stock[i] = malloc(sizeof(t_point) * fdf->width);
		j = 0;
		while (j < fdf->width)
		{
			fdf->xyz_stock[i][j] = malloc(sizeof(t_point));
			fdf->xyz_stock[i][j]->x = j + 1;
			fdf->xyz_stock[i][j]->y = i + 1;
			fdf->xyz_stock[i][j]->z = fdf->num[i][j];
			j++;
		}
		i++;
	}
}
