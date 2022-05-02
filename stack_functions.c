/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <galpers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:11:44 by galpers           #+#    #+#             */
/*   Updated: 2022/05/02 11:50:47 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	stack_size(t_stack *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size + 1);
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	stack_clear(t_stack **lst, int (del)(int))
{
	t_stack	*tmp;

	if (del == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		stack_delone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

void	stack_delone(t_stack *lst, int (del)(int))
{
	if (del == NULL)
		return ;
	if (lst != NULL)
	{	
		(del)(lst->content);
		free(lst);
	}
}

void	stack_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
