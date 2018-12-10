/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:10:32 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/09 17:21:32 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		// ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	while (matrix)
	{
		ft_printf("%s\n", matrix->line);
		matrix = matrix->next;
	}
	close(fd);
}

/*
** dont forget to remove mlx_mouse_hook
*/

int		main(int argc, char **argv)
{
	t_fdf fdf;

	assign_to_zero(&fdf);
	if (argc == 2)
		read_file(&fdf, argv[1]);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1024, 1024, "JOPA");
	mlx_key_hook(fdf.win, exit_fn, &fdf);
	mlx_mouse_hook(fdf.win, mouse_release, &fdf);
	mlx_loop(fdf.mlx);
}
