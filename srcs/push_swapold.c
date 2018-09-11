/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:32 by galemair          #+#    #+#             */
/*   Updated: 2018/05/26 01:20:18 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"

void	divide_median(t_stack **list_a, t_stack **list_b)
{
	int median;

	median = (get_list_size(*list_a) / 2) + find_smallest(*list_a);
	while (check_inferior_value_stack(*list_a, median))
	{
		if ((*list_a)->index > median)
			ra(list_a, list_b, 1);//opti possible pour RRR :)
		else
			pb(list_a, list_b, 1);
	}
}

void	print_quick(t_quick *list)
{
	while (list)
	{
		printf("nbr :%d\n", list->numbers);
		list = list->next;
	}
}
t_quick	*quick_sort_to_a(t_stack **list_a, t_stack **list_b)
{
	int median;
	t_quick *quick;	

	quick = ft_memalloc(sizeof(t_quick));
	quick->numbers = get_list_size(*list_a);
	push_front(&quick);
	while (get_list_size(*list_b) > 2)
	{
		median = (get_list_size(*list_b) / 2) + find_smallest(*list_b);
		while (check_superior_value_stack(*list_b, median))
		{
			if ((*list_b)->index < median)
				rb(list_a, list_b, 1);//opti possible pour RRR :)
			else
			{
				pa(list_a, list_b, 1);
				quick->numbers += 1;
			}
		}
		if (get_list_size(*list_b) > 0)
			push_front(&quick);
	}
	while (get_list_size(*list_b) > 0)
	{
		pa(list_a, list_b, 1);
		quick->numbers += 1;
	}
	//print_qdduick(quick);
	return (quick);
}

void	sort_b(t_stack **list_a, t_stack **list_b, int to_seek)
{
	if (get_list_size(*list_b) / 2 >= (check_value_in_stack(to_seek, *list_b) + 1))
		while ((*list_b)->index != to_seek)
			rb(list_a, list_b, 1);
	else
		while ((*list_b)->index != to_seek)
			rrb(list_a, list_b, 1);
	pa(list_a, list_b, 1);
}
void	sort_list(t_stack **list_a, t_stack **list_b, t_quick *quick)
{
	int last_sorted;

	last_sorted = -1;
	while (quick)
	{
		while (quick->numbers > 0)
		{
	//		if ((*list_a)->next->index == (*list_a)->index + 1 && ((*list_a)->next)->sorted == 0)
	//			sa(list_a, list_b, 1);
			if ((*list_a)->index == last_sorted + 1)
			{
				last_sorted++;
				quick->numbers -= 1;
				(*list_a)->sorted = 1;
				ra(list_a, list_b, 1);
			}
			else if (check_value_in_stack(last_sorted + 1, *list_a))
				pb(list_a, list_b, 1);
			else
				sort_b(list_a, list_b, last_sorted + 1);
		}
		quick = quick->next;
	}
}
void	push_swap(t_stack *list_a, t_stack *list_b)
{
	t_quick *quick;

	pre_sort(list_a);
	divide_median(&list_a, &list_b);
	quick =	quick_sort_to_a(&list_a, &list_b);
	sort_list(&list_a, &list_b, quick);
	//print_quick(quick);
//	printf("LIST_A : \n\n");
//	print_list(list_a);
//	printf("\n\nLIST_B : \n\n");
//	print_list(list_b);
}
//faire des transfusions avec mediane a chaque fois jusqu a 3
//first algo : 
//second algo :
