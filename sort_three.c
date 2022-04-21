/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:11:45 by galpers           #+#    #+#             */
/*   Updated: 2022/04/21 09:11:49 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (get_max(*stack)->next == NULL)
	{
		if (((*stack)->content) < ((*stack)->next->content))
			return ;
		else
		{
			sa(stack);
			return ;
		}
	}
	else if (get_max(*stack) == (*stack))
	{
		ra(stack);
		sort_three(stack);
	}
	else
	{
		rra(stack);
		sort_three(stack);
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		if ((stack_size(get_min(*a)) < ((stack_size(*a) + 1) / 2)))
			min_top(a, rra);
		else
			min_top(a, ra);
		if (is_sorted(*a))
			break ;
		if (((*a)->content) > ((*a)->next->content))
		{
			sa(a);
			continue ;
		}
		pb(a, b);
	}
	if (stack_size(*a) == 3)
	{
		sort_three(a);
	}
	while (stack_size(*b) != 0)
		pa(a, b);
	if (!is_sorted(*a))
		sort_small(a, b);
}
