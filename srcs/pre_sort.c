/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:08:13 by galemair          #+#    #+#             */
/*   Updated: 2018/05/22 15:25:02 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"
#include <limits.h>

void	change_index(t_stack *list, int nb, int index)
{
	while (list->nb != nb)
		list = list->next;
	list->index = index;
}
void		pre_sort(t_stack *list)
{
		int	med_tmp;
		int i;
		t_stack *tmp;
		int min_nb;

		i = 0;
		min_nb = INT_MIN;
		while (i < get_list_size(list))
		{
			med_tmp = INT_MAX;
			tmp = list;
			while (tmp)
			{
				if (tmp->nb <= med_tmp && tmp->nb >= min_nb && tmp->index == -1)
					med_tmp = tmp->nb;						
				tmp = tmp->next;
			}
			min_nb = med_tmp;
			change_index(list, med_tmp, i);
			i++;
		}
}
