/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:16:22 by galpers           #+#    #+#             */
/*   Updated: 2022/04/23 07:56:22 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*get_pos(t_stack *a, int pos)
{
	t_stack	*temp;
	t_stack	*result;
	int lower;

	temp = a;
	result = a;
	if (a == NULL)
		return (NULL);
	lower = 0;
	while (result != NULL)
	{
		while (temp != NULL)
		{
			if ((temp)->content < (result)->content)
				lower++;
			temp = temp->next;
		}
		if (lower == pos)
		{
			return (result);
		}
		result = result->next;
		temp = a;
		lower = 0;
	}
	return (result);
}

void	insert_sorted_b(t_stack **a, t_stack **b, t_stack *median)
{
	t_stack	*min_b;

	min_b = get_min(*b);
	pb(a, b);
	if (stack_size(*b) > 1 && (*b)->content < (min_b->content))
	{
		if((((*a)->content) > (median)->content))
			rr(a, b);
		else
			rb(b);
	}
}
/*
static int find_element_top_down(t_stack **a, t_stack *target)
{
	t_stack *temp;

	temp = *a;
	while ((temp)->next != NULL)
	{
		if((temp)->content < (target)->content)
			return (stack_size(*a) - stack_size(temp));	
		temp = temp->next;
	}	
	return (stack_size(*a) - stack_size(temp));	
}

static int	find_element_bottom_up(t_stack **a, t_stack *pos)
{
	t_stack *temp;
	t_stack *result;

	temp = *a;
	result = *a;
	while (temp != NULL)
	{
		if((temp)->content < ((pos)->content))
			result = temp;
		temp = temp->next;
	}	
	return (stack_size(result));	
}*/

void	sort_pos_to_b(t_stack **a, t_stack **b, t_stack *median)
{
	t_stack *target;

	if (stack_size(*a) > 3)
	{	
		target = get_pos(*a, stack_size(*a) / 2);
		if (((*a)->content) <= ((target)->content))
			insert_sorted_b(a, b, median);
	else
				ra(a);
		sort_pos_to_b(a, b, median);
	}
} 
