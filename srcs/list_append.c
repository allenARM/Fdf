/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:39:49 by amelikia          #+#    #+#             */
/*   Updated: 2018/12/09 17:21:20 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*create_list(t_list *matrix, char *str)
{
	matrix = malloc(sizeof(t_list));
	matrix->line = ft_strdup(str);
	matrix->next = NULL;
	return (matrix);
}

t_list	*list_append(t_list *matrix, char *str)
{
	t_list	*tmp;
	t_list	*new;

	tmp = matrix;
	if (matrix == NULL)
		return (create_list(matrix, str));
	while (matrix->next)
		matrix = matrix->next;
	new = malloc(sizeof(t_list));
	new->line = ft_strdup(str);
	new->next = NULL;
	matrix->next = new;
	return (tmp);
}
