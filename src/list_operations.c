/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:48:47 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/18 14:34:12 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_list_size(t_list *list)
{
	int i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	ft_clean_list(t_list **list)
{
	t_list	*node;

	node = *list;
	if (node && node->next)
		ft_clean_list(&node->next);
	free(node->line);
	free(node);
}

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
