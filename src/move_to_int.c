/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:07:42 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/10 13:20:27 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_data(t_list *matrix, t_fdf *fdf)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (matrix)
	{
		j = 0;
		k = 0;
		fdf->num[i] = (int*)malloc(sizeof(int) * fdf->width);
		line = matrix->line;
		while (j < fdf->width)
		{
			fdf->num[i][j] = ft_atoi(&line[k]);
			while (line[k] && line[k] != ' ')
				k++;
			while (line[k] && line[k] == ' ')
				k++;
			j++;
		}
		i++;
		matrix = matrix->next;
	}
}

void	move_to_int(t_list *matrix, t_fdf *fdf)
{
	int		list_size;

	list_size = ft_list_size(matrix);
	fdf->height = list_size;
	fdf->num = (int**)malloc(sizeof(int*) * (list_size + 1));
	fdf->num[list_size] = NULL;
	fdf->width = find_len(matrix->line);
	copy_data(matrix, fdf);
}
