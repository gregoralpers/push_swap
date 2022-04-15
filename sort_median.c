/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:16:22 by galpers           #+#    #+#             */
/*   Updated: 2022/04/15 10:24:17 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_pos_to_b(t_stack **a, t_stack **b, int len, t_stack *pos)
{
	if (len > 50)
	{
		if (((*a)->content) <= ((pos)->content))
			insert_sorted_b(a, b);
		else 
			ra(a);
		sort_pos_to_b(a, b, stack_size(*a), pos);
	}
} 
