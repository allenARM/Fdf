/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:36:55 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/11 18:57:45 by amelikia         ###   ########.fr       */
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

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	int		**num;
	int		width;
	int		height;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}			t_fdf;

int			exit_fn(int key, t_fdf *fdf);
void		assign_to_zero(t_fdf *fdf);
void		read_file(t_fdf *fdf, char *str);
void		move_to_int(t_list *matrix, t_fdf *fdf);

/*
** utils below
*/

int			ft_list_size(t_list *list);
t_list		*list_append(t_list *matrix, char *str);
int			find_len(char *s);
/*
** delete below later
*/

int			mouse_release(int button, int x, int y, t_fdf *fdf);

#endif
