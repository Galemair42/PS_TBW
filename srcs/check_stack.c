/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:01:59 by galemair          #+#    #+#             */
/*   Updated: 2018/05/25 20:00:12 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "global.h"

int		check_inferior_value_stack(t_stack *list, int median)
{
	while (list)
	{
		if (list->index < median)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_superior_value_stack(t_stack *list, int median)
{
	while (list)
	{
		if (list->index > median)
			return (1);
		list = list->next;
	}
	return (0);
}

int		check_value_in_stack(int value, t_stack *list)
{
	int	count; 

	while (list)
	{
		if (list->index == value)
			return (count);
				count++;
		list = list->next;
	}
	return (0);
}
