/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:32:54 by galpers           #+#    #+#             */
/*   Updated: 2022/04/21 09:11:03 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	check_repeats(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack;
	while (temp)
	{
		temp2 = stack;
		while (temp != temp2)
		{
			if (temp->content == temp2->content)
			{	
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	check_errors(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && ft_isdigit(str[1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
