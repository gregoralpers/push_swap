/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:28:35 by galpers           #+#    #+#             */
/*   Updated: 2022/04/14 09:56:31 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*ft_newstack(int num)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (elem == NULL)
		return (NULL);
	elem->content = num;
	elem->next = NULL;
	return (elem);
}

t_stack	*init_stack_split(char **list)
{
	t_stack	*first;
	t_stack	*temp;
	int		i;

	i = 0;
	first = NULL;
	while (list[i] != NULL)
	{
		if (check_errors(list[i]))
			return (NULL);
		if (i == 0)
		{
			first = ft_newstack(ft_atoi(list[i]));
			first->next = temp;
			temp = first;
		}
		else
		{
			temp->next = ft_newstack(ft_atoi(list[i]));
			temp = temp->next;
		}
		i++;
	}
	temp->next = NULL;
	return (first);
}

t_stack	*initialize_stack(int ac, char **av)
{
	int		i;
	t_stack	*temp;
	t_stack	*first;

	i = 0;
	if (ac == 2)
		return (init_stack_split(ft_split(av[1], ' ')));
	else
	{
		while (++i < ac)
		{
			if (check_errors(av[i]))
				return (0);
			if (i == 1)
			{
				first = ft_newstack(ft_atoi(av[i]));
				first->next = temp;
				temp = first;
			}
			else
			{
				temp->next = ft_newstack(ft_atoi(av[i]));
				temp = temp->next;
			}
		}
		temp->next = NULL;
		return (first);
	}
}