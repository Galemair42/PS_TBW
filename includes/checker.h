/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:28:56 by galemair          #+#    #+#             */
/*   Updated: 2018/05/22 14:56:19 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

typedef struct	s_tab
{
	char		*str;
	void		(*f)(t_stack **list_a, t_stack **list_b, int display);
}				t_tab;
/*
 **------------CHECKER.C-------------
 */
void			checker(t_stack *list_a, t_stack *list_b);

#endif
