/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 18:42:20 by galemair          #+#    #+#             */
/*   Updated: 2018/09/18 16:18:33 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "checker.h"
#include "libft.h"

void	init_part2(t_tab *g_tab)
{
	g_tab[7].str = "rr";
	g_tab[7].f = &rr;
	g_tab[8].str = "rra";
	g_tab[8].f = &rra;
	g_tab[9].str = "rrb";
	g_tab[9].f = &rrb;
	g_tab[10].str = "rrr";
	g_tab[10].f = &rrr;
	g_tab[11].str = "end";
	g_tab[11].f = &error;
}

t_tab	*init_table(void)
{
	t_tab *g_tab;

	g_tab = malloc(sizeof(t_tab) * 12);
	g_tab[0].str = "sa";
	g_tab[0].f = &sa;
	g_tab[1].str = "sb";
	g_tab[1].f = &sb;
	g_tab[2].str = "ss";
	g_tab[2].f = &ss;
	g_tab[3].str = "pa";
	g_tab[3].f = &pa;
	g_tab[4].str = "pb";
	g_tab[4].f = &pb;
	g_tab[5].str = "ra";
	g_tab[5].f = &ra;
	g_tab[6].str = "rb";
	g_tab[6].f = &rb;
	init_part2(g_tab);
	return (g_tab);
}

void	display_check(t_stack *list_a, t_stack *list_b)
{
	if (!(list_a))
	{
		ft_printf("KO\n");
		return ;
	}
	while (list_a->next)
	{
		if ((list_a->next)->nb < list_a->nb)
		{
			ft_printf("KO\n");
			return ;
		}
		list_a = list_a->next;
	}
	if (list_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	free_helper(t_stack *list_a, t_stack *list_b, t_tab *table)
{
	free(table);
	free_list(list_a);
	free_list(list_b);
}

void	checker(t_stack *list_a, t_stack *list_b)
{
	char		*instruction;
	t_tab		*table;
	int			i;

	table = init_table();
	while (get_next_line(0, &instruction))
	{
		i = 0;
		while (ft_strcmp(instruction, table[i].str) != 0 &&
			ft_strcmp("end", table[i].str) != 0)
			i++;
		table[i].f(&list_a, &list_b, 0);
		free(instruction);
		instruction = NULL;
		if (i == 11)
		{
			free_helper(list_a, list_b, table);
			return ;
		}
	}
	display_check(list_a, list_b);
	free_helper(list_a, list_b, table);
}
