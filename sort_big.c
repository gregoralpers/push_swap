/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:58:44 by galpers           #+#    #+#             */
/*   Updated: 2022/04/16 09:58:20 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shared_move(t_stack **a, t_stack **b, t_stack *elem, t_stack *after_me)
{
	if (topr_cost(*b, elem) < toprr_cost(*b, elem))
	{
		if (stack_size(after_me) > stack_size(*a) / 2
			|| topr_cost(*a, after_me) < topr_cost(*b, elem))
			rr(a, b);
		else
			return (0);
	}
	else
	{
		if (stack_size(after_me) < stack_size(*a) / 2
			|| toprr_cost(*a, after_me) < toprr_cost(*b, elem))
			rrr(a, b);
		else
			return (0);
	}
	return (1);
}

void	place_best_top(t_stack **a, t_stack **b, t_stack *elem)
{
	t_stack	*after_me;

	after_me = element_after_me(a, elem);
	while (after_me != *a && elem != *b)
	{
		if (shared_move(a, b, elem, after_me))
			continue ;
		break ;
	}
	while (after_me != *a)
	{
		if (toprr_cost(*a, after_me) < topr_cost(*a, after_me))
			rra(a);
		else
			ra(a);
	}
	while (elem != *b)
	{
		if (toprr_cost(*b, elem) < topr_cost(*b, elem))
			rrb(b);
		else
			rb(b);
	}
}
