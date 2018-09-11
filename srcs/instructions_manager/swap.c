/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:09:08 by galemair          #+#    #+#             */
/*   Updated: 2018/05/22 15:18:26 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void	sb(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack *tmp;

	if (display == 1)
		ft_printf("sb\n");
	if (!(*list_b) || !((*list_b)->next))
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = (*list_b)->next;
	(*list_b)->next = tmp;
}

void	sa(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack *tmp;

	if (display == 1)
		ft_printf("sa\n");
	if (!(*list_a) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = (*list_a)->next;
	(*list_a)->next = tmp;
}
void	ss(t_stack **list_a, t_stack **list_b, int display)
{
	if (display == 1)
		ft_printf("ss\n");
	sa(list_a, list_b, 0);
	sb(list_a, list_b, 0);
}
