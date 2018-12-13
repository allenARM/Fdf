/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:21:29 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/12 18:08:28 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_nums(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%-3d", fdf->num[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_figure(t_fdf *fdf)
{
	int i;
	int j;
	int z = 50;
	int x = 50;
	int y;
	int off;

	off = 50;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			z = fdf->num[i][j];
			x = ((x - y) + i + off) * cos(0.523599);
			y = -z + ((x + y) + j + off) * sin(0.523599);
			mlx_pixel_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

/*
** remove print_nums later
*/

void	read_file(t_fdf *fdf, char *str)
{
	int		fd;
	t_list	*matrix;
	char	*line;

	matrix = NULL;
	fdf->x1 = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		matrix = list_append(matrix, line);
		ft_strdel(&line);
	}
	move_to_int(matrix, fdf);
	make_data(fdf)
	// print_figure(fdf);
	print_nums(fdf);
	close(fd);
}
