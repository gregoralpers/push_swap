/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:02:22 by galpers           #+#    #+#             */
/*   Updated: 2022/04/21 09:40:32 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/push_swap.h"

int	topr_cost(t_stack *stack, t_stack *elem)
{
	return (stack_size(stack) - stack_size(elem));
}

int	toprr_cost(t_stack *stack, t_stack *elem)
{
	(void)stack;
	return (stack_size(elem));
}

t_stack	*element_after_me(t_stack **stack, t_stack *elem)
{
	t_stack	*temp;

	if ((*stack)->content > elem->content
		&& (stack_last(*stack)->content) < elem->content)
		return (*stack);
	if (get_min(*stack)->content > elem->content)
		return (get_min(*stack));
	else if (get_max(*stack)->content < (elem->content))
		return (get_max(*stack));
	temp = *stack;
	while (temp->next)
	{
		if (temp->content < (elem->content)
			&& (temp->next->content > elem->content))
			break ;
		temp = temp->next;
	}
	if (temp->next)
		return (temp->next);
	else
		return (temp);
}

static int	align_elem_cost(t_stack **a, t_stack **b, t_stack *elem)
{
	int		b_mincost;
	int		a_mincost;
	t_stack	*a_elem;

	a_elem = element_after_me(a, elem);
	if (toprr_cost(*b, elem) < topr_cost(*b, elem))
		b_mincost = toprr_cost(*b, elem);
	else
		b_mincost = topr_cost(*b, elem);
	if (b_mincost > toprr_cost(*a, a_elem)
		|| b_mincost > topr_cost(*a, a_elem))
		return (b_mincost);
	if (toprr_cost(*a, a_elem) < topr_cost(*a, a_elem))
		a_mincost = toprr_cost(*a, a_elem);
	else
		a_mincost = topr_cost(*a, a_elem);
	return (a_mincost + b_mincost);
}

t_stack	*get_cheapest_elem(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*res;
	int		cost;
	int		last_cost;

	temp = *b;
	last_cost = -1;
	while (temp)
	{
		cost = align_elem_cost(a, b, temp);
		if (cost < last_cost || last_cost == -1)
		{
			last_cost = cost;
			res = temp;
		}
		temp = temp->next;
	}
	return (res);
}
