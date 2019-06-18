/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:02:20 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/18 14:30:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clean_t_point_matrix(t_point ****arr, int height, int width)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			free((*arr)[i][j]);
			++j;
		}
		free((*arr)[i]);
		++i;
	}
	free(*arr);
}

void		clean_and_exit(t_fdf *fdf)
{
	free(fdf->first);
	free(fdf->second);
	free(fdf->angle);
	clean_t_point_matrix(&fdf->xyz_stock, fdf->height, fdf->width);
	exit(1);
}
