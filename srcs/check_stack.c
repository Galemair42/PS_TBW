/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:01:59 by galemair          #+#    #+#             */
/*   Updated: 2018/09/12 11:45:53 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "global.h"

int		check_inferior_value_stack(t_stack *list, int median)
{
	int nb;

	nb = 0;
	while (list)
	{
		if (list->index < median)
			nb++;
		list = list->next;
	}
	return (nb);
}

int		check_superior_value_stack(t_stack *list, int median)
{
	int nb;

	nb = 0;
	while (list)
	{
		if (list->index > median)
			nb++;
		list = list->next;
	}
	return (nb);
}

int		check_superior_value_chandelle(t_stack *list, int median, int nb)
{
	int superior_value;

	superior_value = 0;
	while (list && nb > 0)
	{
		if (list->index > median)
			superior_value++;
		list = list->next;
		nb--;
	}
	return (superior_value);
}

int		check_value_in_stack(int value, t_stack *list)
{
	int	count;

	while (list)
	{
		if (list->index == value)
			return (count);
		count++;
		list = list->next;
	}
	return (0);
}
