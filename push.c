/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:36:48 by galpers           #+#    #+#             */
/*   Updated: 2022/05/02 11:45:30 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (stack_size(*b) > 0)
	{
		push(a, stack_new(pullnumber(b)));
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (stack_size(*a) > 0)
	{
		push(b, stack_new(pullnumber(a)));
		write(1, "pb\n", 3);
	}
}

void	push(t_stack **s, t_stack *new)
{
	if (s == NULL)
		return ;
	stack_add_front(s, new);
}

int	pullnumber(t_stack **s)
{
	int		content;
	t_stack	*pulledlist;

	if (*s == NULL || s == NULL)
		return (0);
	pulledlist = *s;
	*s = pulledlist->next;
	content = pulledlist->content;
	stack_delone(pulledlist, NULL);
	return (content);
}
