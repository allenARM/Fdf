/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:21:29 by amelikia          #+#    #+#             */
/*   Updated: 2019/01/07 12:31:53 by amelikia         ###   ########.fr       */
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

	i = 0;
	while (i < fdf->height - 1)
	{
		j = 0;
		while (j < fdf->width - 1)
		{
			fdf->x1 = fdf->xyz_modif[i][j]->x;
			fdf->y1 = fdf->xyz_modif[i][j]->y;
			fdf->x2 = fdf->xyz_modif[i + 1][j]->x;
			fdf->y2 = fdf->xyz_modif[i + 1][j]->y;
			printline(fdf);
			fdf->x2 = fdf->xyz_modif[i][j + 1]->x;
			fdf->y2 = fdf->xyz_modif[i][j + 1]->y;
			printline(fdf);
			j++;
		}
		i++;
	}
}

void	print_stock(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%2d%2d|%3d| ", fdf->xyz_stock[i][j]->x,\
			fdf->xyz_stock[i][j]->y, fdf->xyz_stock[i][j]->z);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_modif(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%3d:%3d | ", fdf->xyz_modif[i][j]->x,\
			fdf->xyz_modif[i][j]->y);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

/*
** remove everything above
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
	print_nums(fdf);
	save_data_in_stock(fdf);
	print_stock(fdf);
	make_modified(fdf);
	ft_printf("\n----------\n");
	print_modif(fdf);
	print_figure(fdf);
	close(fd);
}
