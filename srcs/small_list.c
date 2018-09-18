/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:19:07 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 15:48:52 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_biggest_to_right(t_stack **list_a, t_stack **list_b)
{
	if (find_biggest(*list_a) == 1)
		ra(list_a, list_b, DISPLAY);
	else if (find_biggest(*list_a) == 2)
		rra(list_a, list_b, DISPLAY);
}

void	sort_3_elems(t_stack **list_a, t_stack **list_b)
{
	if (get_list_size(*list_a) == 1)
		return ;
	if (get_list_size(*list_a) == 2)
	{
		if ((*list_a)->index > ((*list_a)->next)->index)
			ra(list_a, list_b, DISPLAY);
		return ;
	}
	put_biggest_to_right(list_a, list_b);
	if ((*list_a)->index > ((*list_a)->next)->index)
		sa(list_a, list_b, DISPLAY);
}

void	manage_small_list(t_stack **list_a, t_stack **list_b)
{
	int			last_sorted;
	int			median;
	t_quick		*to_free;

	median = -1;
	if (get_list_size(*list_a) > 90)
		median = 3;
	to_free = divide_median(list_a, list_b, median);
	sort_3_elems(list_a, list_b);
	last_sorted = ((*list_a)->index - 1);
	while (get_list_size(*list_b) > 0)
	{
		sort_b(list_a, list_b, last_sorted);
		last_sorted--;
	}
	free_quick(to_free);
}
