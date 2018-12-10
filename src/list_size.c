/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:48:47 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/09 16:54:14 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	list_size(t_list *list)
{
	int i;

	i = 1;
	if (list == NULL)
		return (0);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
