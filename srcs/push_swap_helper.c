/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <galemair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 08:07:28 by galemair          #+#    #+#             */
/*   Updated: 2018/09/13 14:13:35 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		opti_sort_list(t_stack **list_a, t_stack **list_b, int *last_sorted)
{
	(*last_sorted) += 2;
	rra(list_a, list_b, DISPLAY);
	sa(list_a, list_b, DISPLAY);
	ra(list_a, list_b, DISPLAY);
	ra(list_a, list_b, DISPLAY);
	return (0);
}

void	divide_median_to_a(t_stack **list_a, t_stack **list_b)
{
	int	median;

	while (get_list_size(*list_b) > 3)
	{
		median = (get_list_size(*list_b) / 3) + find_smallest(*list_b, -1);
		while (check_superior_value_stack(*list_b, median))
		{
			if ((*list_b)->index <= median)
				rb(list_a, list_b, DISPLAY);
			else
				pa(list_a, list_b, DISPLAY);
		}
	}
	while (get_list_size(*list_b) > 0)
		pa(list_a, list_b, DISPLAY);
}

int		main_loop_to_a(t_stack **list_a, t_stack **list_b, int numbers,
		int median)
{
	int	right;

	right = 0;
	while (numbers > 3)
	{
		median = (numbers / 2) + find_smallest(*list_b, numbers);
		while (check_superior_value_chandelle(*list_b, median, numbers - right))
		{
			if ((*list_b)->index >= median && numbers-- > -42)
				pa(list_a, list_b, DISPLAY);
			else
			{
				rb(list_a, list_b, DISPLAY);
				right++;
			}
		}
		while (right > 0)
		{
			rrb(list_a, list_b, DISPLAY);
			right--;
		}
	}
	return (numbers);
}
