/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:26:32 by galemair          #+#    #+#             */
/*   Updated: 2018/09/11 22:32:48 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"

int n = 0;
void	print_quick(t_stack *list)
{
	while (list)
	{
		printf("nbr :%d\n", list->nb);
		list = list->next;
	}
}

int		divide_median_to(t_stack **list_a, t_stack **list_b)
{
	int median;

	while (get_list_size(*list_a) > 3)
	{
		median = (get_list_size(*list_a) / 2) + find_smallest(*list_a);
		//printf("MEDIAN HERE = %d\n", median);
		while (check_inferior_value_stack(*list_a, median))
		{
			if ((*list_a)->index > median)
				ra(list_a, list_b, DISPLAY);//opti possible pour RRR :)
			else
				pb(list_a, list_b, DISPLAY);
		}
	}
}



void	quick_sort_to_a(t_stack **list_a, t_stack **list_b)
{
	int median;

	while (get_list_size(*list_b) > 2)
	{
		median = (get_list_size(*list_b) / 2) + find_smallest(*list_b);
		while (check_superior_value_stack(*list_b, median))
		{
			if ((*list_b)->index < median)
				rb(list_a, list_b, DISPLAY);
			else
			{
				pa(list_a, list_b, DISPLAY);
			//	if (get_list_size(*list_a) >= 2)
			//		if ((*list_a)->index < ((*list_a)->next)->index)
			//			sa(list_a, list_b, DISPLAY);
			}

		}
	}
	while (get_list_size(*list_b) > 0)
		pa(list_a, list_b, DISPLAY);
//	print_list(*list_a);
}

void	sort_b(t_stack **list_a, t_stack **list_b, int to_seek)
{
	if (get_list_size(*list_b) / 2 >= (check_value_in_stack(to_seek, *list_b) + 1))
		while ((*list_b)->index != to_seek)
			rb(list_a, list_b, DISPLAY);
	else
		while ((*list_b)->index != to_seek)
			rrb(list_a, list_b, DISPLAY);
	pa(list_a, list_b, DISPLAY);
}
void	sort_list(t_stack **list_a, t_stack **list_b)
{
	int last_sorted;
	int flag_sa = 0;

	last_sorted = -1;
	while (list_is_sorted(*list_a, *list_b) == 0)
	{
		if ((*list_a)->index == last_sorted + 1 && flag_sa == 1)
		{
			last_sorted += 2;
			rra(list_a, list_b, DISPLAY);
			sa(list_a, list_b, DISPLAY);
			ra(list_a, list_b, DISPLAY);
			ra(list_a, list_b, DISPLAY);
			flag_sa = 0;
			n++;
		}
		else if ((*list_a)->index == last_sorted + 1)
		{
			last_sorted++;
			(*list_a)->sorted = 1;
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
void	push_swap(t_stack *list_a, t_stack *list_b)
{
//	pre_sort(list_a);
//	start_recursive_quicksort(&list_a, &list_b);
//	divide_median(&list_a, &list_b);
//	quick_sort_to_a(&list_a, &list_b);
	sort_list(&list_a, &list_b);
	//printf("%d\n", n);
	//print_quick(quick);
//	printf("LIST_A : \n\n");
//	print_list(list_a);
//	printf("\n\nLIST_B : \n\n");
//	print_list(list_b);
}
//faire des transfusions avec mediane a chaque fois jusqu a 3
//first algo : 
//second algo :
