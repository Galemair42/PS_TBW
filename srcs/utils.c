/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:06:28 by galemair          #+#    #+#             */
/*   Updated: 2018/05/23 17:25:48 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include <limits.h>

int		find_smallest(t_stack *list)
{
	int smallest;

	smallest = list->index;
	while (list)
	{
		if (list->index < smallest)
			smallest = list->index;
		list = list->next;
	}
	return (smallest);
}
int		get_list_size(t_stack *list)
{
	int count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}
