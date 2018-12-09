/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:38:14 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/09 15:38:22 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fn(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(1);
	if (key == 42)
		mlx_clear_window(fdf->mlx, fdf->win);
	return (0);
}
