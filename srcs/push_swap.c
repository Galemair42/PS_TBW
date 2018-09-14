/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:32 by galemair          #+#    #+#             */
/*   Updated: 2018/09/13 15:17:11 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"

t_quick		*divide_median(t_stack **list_a, t_stack **list_b, int m)
{
	int		median;
	t_quick	*quick;
	int		remaining_values;

	remaining_values = m;
	if (m == -1 && (m = 2) == 2)
		remaining_values = 3;
	quick = ft_memalloc(sizeof(t_quick));
	while (get_list_size(*list_a) > remaining_values)
	{
		median = (get_list_size(*list_a) / m) + find_smallest(*list_a, -1);
		while (check_inferior_value_stack(*list_a, median) > 0)
		{
			if ((*list_a)->index >= median)
				ra(list_a, list_b, DISPLAY);
			else
			{
				pb(list_a, list_b, DISPLAY);
				quick->numbers++;
			}
			if (check_inferior_value_stack(*list_a, median) == 0)
				push_front(&quick);
		}
	}
	return (quick);
}

void		quick_sort_to_a(t_stack **list_a, t_stack **list_b, t_quick *quick)
{
	int median;
	int numbers;

	quick = quick->next;
	while (quick)
	{
		numbers = quick->numbers;
		numbers = main_loop_to_a(list_a, list_b, quick->numbers, median);
		while (numbers > 0)
		{
			pa(list_a, list_b, DISPLAY);
			numbers--;
		}
		quick = quick->next;
	}
	divide_median_to_a(list_a, list_b);
}

void		sort_b(t_stack **list_a, t_stack **list_b, int to_seek)
{
	if (get_list_size(*list_b) / 2 >=
		(check_value_in_stack(to_seek, *list_b) + 1))
		while ((*list_b)->index != to_seek)
			rb(list_a, list_b, DISPLAY);
	else
		while ((*list_b)->index != to_seek)
			rrb(list_a, list_b, DISPLAY);
	pa(list_a, list_b, DISPLAY);
}

void		sort_list(t_stack **list_a, t_stack **list_b)
{
	int last_sorted;
	int flag_sa;

	last_sorted = -1;
	flag_sa = 0;
	while (list_is_sorted(*list_a, *list_b) == 0)
	{
		if ((*list_a)->index == last_sorted + 1 && flag_sa == 1)
			flag_sa = opti_sort_list(list_a, list_b, &last_sorted);
		if ((*list_a)->index == last_sorted + 1)
		{
			last_sorted++;
			ra(list_a, list_b, DISPLAY);
		}
		else if ((*list_a)->index == last_sorted + 2)
		{
			ra(list_a, list_b, DISPLAY);
			flag_sa = 1;
		}
		else if (check_value_in_stack(last_sorted + 1, *list_a))
			pb(list_a, list_b, DISPLAY);
		else
			sort_b(list_a, list_b, last_sorted + 1);
	}
}

void		push_swap(t_stack *list_a, t_stack *list_b)
{
	t_quick *quick;

	pre_sort(list_a);
	if (list_is_sorted(list_a, list_b))
		return ;
	if (get_list_size(list_a) <= 200)
	{
		manage_small_list(&list_a, &list_b);
		return ;
	}
	quick = divide_median(&list_a, &list_b, 5);
	quick_sort_to_a(&list_a, &list_b, quick);
	sort_list(&list_a, &list_b);
}
