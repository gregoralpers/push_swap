/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:17:39 by galpers           #+#    #+#             */
/*   Updated: 2022/04/14 10:34:34 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

long	get_mean(t_stack *stack)
{
	t_stack	*temp;
	long		mean;

	temp = stack;
	mean = 0;
	while (temp != NULL)
	{
		mean += (temp->content);
		temp = temp->next;
	}
	return (mean / stack_size(stack));
}

t_stack	*get_max(t_stack *a)
{
	t_stack	*temp;
	t_stack	*result;

	temp = a;
	result = temp;
	if (a == NULL)
		return (NULL);
	while (temp != NULL)
	{
		if (temp->content > result->content)
			result = temp;
		temp = temp->next;
	}
	return (result);
}

t_stack	*get_min(t_stack *a)
{
	t_stack	*temp;
	t_stack	*result;

	temp = a;
	result = temp;
	if (a == NULL)
		return (NULL);
	while (temp != NULL)
	{
		if (temp->content < result->content)
			result = temp;
		temp = temp->next;
	}
	return (result);
}

void	min_top(t_stack **stack, void func(t_stack **))
{
	int	min;

	min = get_min(*stack)->content;
	while (((*stack)->content) != min)
		func(stack);
}
