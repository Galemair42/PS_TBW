/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:06:28 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 15:41:06 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include <limits.h>

void	push_front(t_quick **begin_list)
{
	t_quick *tmp;

	tmp = ft_memalloc(sizeof(t_quick));
	tmp->next = *begin_list;
	*begin_list = tmp;
}

void	free_quick(t_quick *list)
{
	t_quick *tmp;

	while (list)
	{
		tmp = list;
		free(tmp);
		list = list->next;
	}
}

void	free_list(t_stack *list_a)
{
	t_stack *tmp;

	while (list_a)
	{
		tmp = list_a;
		free(tmp);
		list_a = list_a->next;
	}
}

int		find_smallest(t_stack *list, int nb)
{
	int smallest;

	smallest = list->index;
	while ((list && nb > 0) || (list && nb == -1))
	{
		if (list->index < smallest)
			smallest = list->index;
		if (nb != -1)
			nb--;
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
