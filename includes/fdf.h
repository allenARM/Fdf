/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:36:55 by amelikia          #+#    #+#             */
/*   Updated: 2019/04/24 12:59:58 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct		s_list
{
	char			*line;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	int			x;
	int			y;
	int			z;
}					t_point;

typedef struct		s_double_point
{
	double		x;
	double		y;
}					t_double_point;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	t_double_point	*first;
	t_double_point	*second;
	int				**num;
	int				width;
	int				height;
	t_double_point	*angle;
	double			color_incr;
	t_point			***xyz_stock;
	t_point			***xyz_modif;
}					t_fdf;

int					exit_fn(int key, t_fdf *fdf, int i);
void				assign_to_zero(t_fdf *fdf);
void				read_file(t_fdf *fdf, char *str);
void				move_to_int(t_list *matrix, t_fdf *fdf);
void				save_data_in_stock(t_fdf *fdf);
void				make_modified(t_fdf *fdf);
void				printline(t_fdf *fdf);
void				print_figure(t_fdf *fdf);

/*
** utils below
*/

int					ft_list_size(t_list *list);
t_list				*list_append(t_list *matrix, char *str);
int					find_len(char *s);
/*
** delete below later
*/

int					mouse_release(int button, int x, int y, t_fdf *fdf);

#endif
