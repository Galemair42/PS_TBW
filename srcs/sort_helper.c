/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:24:05 by galemair          #+#    #+#             */
/*   Updated: 2018/05/26 01:42:27 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"

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
int		last_elem(t_stack *list)
{
	while(list)
		list = list->next;
	return (list->index);
}
//void	sort_3elems(t_stack **list_a, t_stack **list_b)
//{
//	if (get_list_size(*list_b) == 1)
//		pa(list_a, list_b, 1);
//	else if (getlist_size(*list_b) == 2)
//	{
//		check_ss(list_a, list_b, 'b');
//		pa(list_a, list_b, 1);
//		pa(list_a, list_b, 1);
//	}
//	else if (getlist_size(*list_b) == 3)
//	{
//
//	}
//}
void	check_ss(t_stack **list_a, t_stack **list_b, char list)
{
	int size_list_a;
	int size_list_b;

	size_list_a = get_list_size(*list_a);
	size_list_b = get_list_size(*list_b);

//	if (size_list_a >= 2 && size_list_b >= 2 && (*list_a)->index > ((*list_a)->next)->index && (*list_b)->index <
//		((*list_b)->next)->index && ((*list_a)->next)->sorted == 0)
//		ss(list_a, list_b, 1);
	if (size_list_a >= 2 && (*list_a)->index > ((*list_a)->next)->index && list == 'a' && ((*list_a)->next)->sorted == 0)
		sa(list_a, list_b, 1);
	else if (size_list_b >= 2 && (*list_b)->index < ((*list_b)->next)->index && list == 'b')
		sb(list_a, list_b, 1);
}
