/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:30:38 by galemair          #+#    #+#             */
/*   Updated: 2018/05/25 20:32:13 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

#include <stdlib.h>
#include "libft.h"

typedef	struct s_stack	t_stack;

struct			s_stack
{
	int			nb;
	int			index;
	int			sorted;
	t_stack		*next;
};

typedef	struct	s_quick	t_quick;

struct			s_quick
{
	int			numbers;
	t_quick		*next;
};

void			ft_printf(const char *str, ...);
void			sa(t_stack **list_a, t_stack **list_b, int display);
void			sb(t_stack **list_a, t_stack **list_b, int display);
void			ss(t_stack **list_a, t_stack **list_b, int display);
void			pa(t_stack **list_a, t_stack **list_b, int display);
void			pb(t_stack **list_a, t_stack **list_b, int display);
void			ra(t_stack **list_a, t_stack **list_b, int display);
void			rb(t_stack **list_a, t_stack **list_b, int display);
void			rr(t_stack **list_a, t_stack **list_b, int display);
void			rra(t_stack **list_a, t_stack **list_b, int display);
void			rrb(t_stack **list_a, t_stack **list_b, int display);
void			rrr(t_stack **list_a, t_stack **list_b, int display);
void			error(t_stack **list_a, t_stack **list_b, int display);
/*
 **-------------DEBUG.C--------------
 */
void			print_list(t_stack *list);
/*
 **-------------CREATE_LIST.C--------
 */
int				create_list(int count, char **numbers, t_stack **list_a);
void			push_front(t_quick **begin_list);

#endif
