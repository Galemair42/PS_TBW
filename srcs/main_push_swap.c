/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:53:52 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 15:36:54 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc > 1)
	{
		if (create_list(argc - 1, argv + 1, &list_a) == 0)
		{
			free_list(list_a);
			error(&list_a, &list_b, 0);
			return (0);
		}
		push_swap(list_a, list_b);
	}
	return (0);
}
