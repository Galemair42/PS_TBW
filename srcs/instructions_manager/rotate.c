/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:18:03 by galemair          #+#    #+#             */
/*   Updated: 2018/09/12 14:33:12 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void		ra(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack *tmp;

	if (display == 1)
		ft_printf("ra\n");
	if (!((*list_a)->next) || !((*list_a)->next))
		return ;
	tmp = *list_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list_a;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = NULL;
}

void		rb(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack *tmp;

	if (display == 1)
		ft_printf("rb\n");
	if (!((*list_b)->next) || !((*list_b)->next))
		return ;
	tmp = *list_b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list_b;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = NULL;
}

void		rr(t_stack **list_a, t_stack **list_b, int display)
{
	if (display == 1)
		ft_printf("rr\n");
	ra(list_a, list_b, 0);
	rb(list_a, list_b, 0);
}
