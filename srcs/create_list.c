/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:48:00 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 15:40:36 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int		check_doublon(t_stack *list_a, int number)
{
	while (list_a)
	{
		if (list_a->nb == number)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}

int		check_error_int(char *number, int length)
{
	char max[11];
	char min[12];

	ft_strcpy(max, "2147483647");
	ft_strcpy(min, "-2147483648");
	if (*number == '-')
	{
		if (length < 11)
			return (1);
		if (length > 11 || strncmp(min, number, length) < 0)
			return (0);
	}
	else
	{
		if (length < 10)
			return (1);
		if (length > 10 || strncmp(max, number, length) < 0)
			return (0);
	}
	return (1);
}

int		ft_get_value(char **str, int *value, t_stack *list_a)
{
	int		length;
	char	*tmp;

	length = 0;
	tmp = *str;
	if (*tmp == '-')
	{
		tmp++;
		length = 1;
	}
	if (!(*tmp) || ft_isdigit(*tmp) == 0)
		return (0);
	while (*tmp && *tmp == '0')
		tmp++;
	while (*tmp && ft_isdigit(*tmp))
	{
		tmp++;
		length++;
	}
	if (check_error_int(*str, length) == 0 ||
		check_doublon(list_a, ft_atoi(*str)) == 0)
		return (0);
	*value = ft_atoi(*str);
	*str = tmp - 1;
	return (1);
}

void	create_elems(t_stack **list_a, int number)
{
	t_stack *tmp;

	if (!(*list_a))
	{
		*list_a = malloc(sizeof(t_stack));
		(*list_a)->nb = number;
		(*list_a)->index = -1;
		(*list_a)->next = NULL;
		return ;
	}
	tmp = *list_a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_stack));
	(tmp->next)->nb = number;
	(tmp->next)->index = -1;
	(tmp->next)->next = NULL;
}

int		create_list(int count, char **numbers, t_stack **list_a)
{
	int		current_value;
	char	*tmp;

	while (count > 0)
	{
		tmp = *numbers;
		while (*tmp)
		{
			if (ft_isdigit(*tmp) || *tmp == '-')
			{
				if (ft_get_value(&tmp, &current_value, *list_a) == 0)
					return (0);
				create_elems(list_a, current_value);
			}
			else if (*tmp != ' ')
				return (0);
			tmp++;
		}
		count--;
		numbers++;
	}
	return (1);
}
