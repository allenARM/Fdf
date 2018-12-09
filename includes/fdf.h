/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:36:55 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/09 15:49:25 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	int		**num;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
}				t_fdf;

int			exit_fn(int key, t_fdf *fdf);
void		assign_to_zero(t_fdf *fdf);
/*
** delete below later
*/

int			mouse_release(int button, int x, int y, t_fdf *fdf);

#endif
