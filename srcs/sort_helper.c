/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:24:05 by galemair          #+#    #+#             */
/*   Updated: 2018/09/13 14:06:39 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"

int		last_elem(t_stack *list)
{
	while (list)
		list = list->next;
	return (list->index);
}

int		list_is_sorted(t_stack *list_a, t_stack *list_b)
{
	while (list_a->next)
	{
		if ((list_a->next)->nb < list_a->nb)
			return (0);
		list_a = list_a->next;
	}
	if (list_b == NULL)
		return (1);
	return (0);
}

int		find_biggest(t_stack *list)
{
	int	cmpt;
	int biggest;
	int current_value;

	current_value = 0;
	cmpt = 1;
	biggest = 1;
	while (list)
	{
		if (list->index > current_value)
		{
			current_value = list->index;
			biggest = cmpt;
		}
		list = list->next;
		cmpt++;
	}
	return (biggest);
}

int		find_distance_from_end(t_stack *list, int to_seek)
{
	int distance_from_start;
	int distance_from_end;

	distance_from_start = 0;
	distance_from_end = get_list_size(list) - 1;
	while (list)
	{
		if (list->index == to_seek)
			break ;
		list = list->next;
		distance_from_start++;
		distance_from_end--;
	}
	if (distance_from_start < distance_from_end)
		return (distance_from_start);
	return (distance_from_end);
}
