/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:58:44 by galpers           #+#    #+#             */
/*   Updated: 2022/04/27 14:16:19 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

static void	insert_sorted_b_big(t_stack **a, t_stack **b, t_stack *target)
{
	t_stack	*min_b;

	min_b = get_min(*b);
	pb(a, b);
	if (stack_size(*b) > 1 && (*b)->content < (min_b->content))
	{
		if ((*a)->content > (target)->content)
			rr(a, b);
		else
			rb(b);
	}
}

void	sort_pos_to_b_big(t_stack **a, t_stack **b, t_stack *target, int num)
{

	while (stack_size(*a) > num && stack_size(*a) > 3)
	{	
		if (((*a)->content) <= ((target)->content))
			insert_sorted_b_big(a, b, target);
		else
			ra(a);
		sort_pos_to_b_big(a, b, target, num);
	}
} 