/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:15:32 by galemair          #+#    #+#             */
/*   Updated: 2018/05/25 20:33:14 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "global.h"

# define DISPLAY 1
void	push_swap(t_stack *list_a, t_stack *list_b);

/*
**			DEBUG.C
*/
void	print_list(t_stack *list);
/*
**			CHECK_STACK.C
*/
int		check_inferior_value_stack(t_stack *list, int median);
int		check_superior_value_stack(t_stack *list, int median);
int		check_value_in_stack(int value, t_stack *list);
/*
**			PRE_SORT.C
*/
void	pre_sort(t_stack *list);
/*
**			UTILS.C
*/
int		get_list_size(t_stack *list);
int		find_smallest(t_stack *list);
/*
**			SORT_HELPER.C
*/
int		last_elem(t_stack *list);
void	sort_3elems(t_stack **list_a, t_stack **list_b);
void	check_ss(t_stack **list_a, t_stack **list_b, char list);
int	list_is_sorted(t_stack *list_a, t_stack *list_b);
#endif
