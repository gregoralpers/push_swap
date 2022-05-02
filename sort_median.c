/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:16:22 by galpers           #+#    #+#             */
/*   Updated: 2022/05/02 12:06:37 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*get_pos(t_stack *a, int pos)
{
	t_stack	*temp;
	t_stack	*result;
	int		lower;

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
			return (result);
		result = result->next;
		temp = a;
		lower = 0;
	}
	return (result);
}

void	insert_sorted_b(t_stack **a, t_stack **b, int i)
{
	t_stack	*min_b;
	int		median_a;

	min_b = get_min(*b);
	pb(a, b);
	median_a = get_pos(*a, stack_size(*a) / 2)->content;
	if (stack_size(*b) > 1 && (*b)->content < (min_b->content))
	{
		if ((i == 0) && (((*a)->content > median_a) || ((*a) == get_min(*a))))
			rr(a, b);
		else if ((i == 1) && ((*a)->content > stack_last(*a)->content))
			rr(a, b);
		else
			rb(b);
	}
}

static void	create_lis(t_stack **a, t_stack **b, int i)
{
	int	nbr;
	int	last_nbr;
	int	next_nbr;

	nbr = (*a)->content;
	last_nbr = stack_last(*a)->content;
	next_nbr = (*a)->next->content;
	if (next_nbr > last_nbr && next_nbr < nbr)
	{	
		if ((stack_size(*b) > 1) && ((*b)->content < (*b)->next->content))
			ss(a, b);
		else
			sa(a);
	}
	else if ((*a)->content > stack_last(*a)->content)
		ra(a);
	else
		insert_sorted_b(a, b, i);
}

void	sort_pos_to_b(t_stack **a, t_stack **b, int i)
{
	t_stack	*target;

	target = get_pos(*a, stack_size(*a) / 2);
	if (stack_size(*a) > 3 && !(is_sorted(*a)))
	{	
		if ((*a) == get_min(*a))
		{
			i = 1;
			ra(a);
		}
		else if ((i == 1) && ((*a)->next != NULL))
		{
			create_lis(a, b, i);
			sort_pos_to_b(a, b, i);
		}
		else if (((*a)->content) <= ((target)->content))
			insert_sorted_b(a, b, i);
		else
			ra(a);
		sort_pos_to_b(a, b, i);
	}
}
