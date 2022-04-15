/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:58:44 by galpers           #+#    #+#             */
/*   Updated: 2022/04/14 18:17:36 by galpers          ###   ########.fr       */
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

void	insert_sorted_b(t_stack **a, t_stack **b)
{
	t_stack	*min_b;

	min_b = get_min(*b);
	pb(a, b);
	if (stack_size(*b) > 1 && (*b)->content < (min_b->content))
			rb(b);
}

void	sort_mean_to_b(t_stack **a, t_stack **b, int len, int abs_mean)
{
	 int	mean;

	mean = get_mean(*a);
	if (len > 3)
	{
		if (((*a)->content) <= mean)
			insert_sorted_b(a, b);
		else
			ra(a);
		sort_mean_to_b(a, b, stack_size(*a), abs_mean);
	}
}
