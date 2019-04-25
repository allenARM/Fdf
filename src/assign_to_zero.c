/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_to_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:40:21 by amelikia          #+#    #+#             */
/*   Updated: 2019/01/07 12:39:28 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_to_zero(t_fdf *fdf)
{
	fdf->first = (t_double_point *)malloc(sizeof(t_double_point));
	fdf->second = (t_double_point *)malloc(sizeof(t_double_point));
	fdf->angle = (t_double_point *)malloc(sizeof(t_double_point));
	fdf->first->x = 0;
	fdf->first->y = 0;
	fdf->second->x = 0;
	fdf->second->y = 0;
	fdf->angle->x = 0.523599;
	fdf->angle->y = 0.523599;
}
