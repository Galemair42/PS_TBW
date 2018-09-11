/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:07:55 by galemair          #+#    #+#             */
/*   Updated: 2018/05/23 17:22:35 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

void		pa(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack	*tmp;

	if (display == 1)
		ft_printf("pa\n");
	if (*list_b == NULL)
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = *list_a;
	*list_a = tmp;
}
void		pb(t_stack **list_a, t_stack **list_b, int display)
{
	t_stack	*tmp;

	if (display == 1)
		ft_printf("pb\n");
	if (*list_a == NULL)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = *list_b;
	*list_b = tmp;
}
