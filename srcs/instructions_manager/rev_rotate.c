/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:19:30 by galemair          #+#    #+#             */
/*   Updated: 2018/09/12 14:32:20 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void		rra(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack *tmp;

	if (display == 1)
		ft_printf("rra\n");
	if (!(*list_a) || !(*list_a)->next)
		return ;
	tmp = *list_a;
	while ((tmp->next)->next)
		tmp = tmp->next;
	(tmp->next)->next = *list_a;
	*list_a = tmp->next;
	tmp->next = NULL;
}

void		rrb(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack *tmp;

	if (display == 1)
		ft_printf("rrb\n");
	if (!(*list_b) || !(*list_b)->next)
		return ;
	tmp = *list_b;
	while ((tmp->next)->next)
		tmp = tmp->next;
	(tmp->next)->next = *list_b;
	*list_b = tmp->next;
	tmp->next = NULL;
}

void		rrr(t_stack **list_a, t_stack **list_b, int display)
{
	if (display == 1)
		ft_printf("rrr\n");
	rra(list_a, list_b, 0);
	rrb(list_a, list_b, 0);
}
