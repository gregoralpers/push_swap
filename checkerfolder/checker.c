/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:37:46 by galpers           #+#    #+#             */
/*   Updated: 2022/04/28 14:46:09 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	make_action(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		sa(a);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		sb(b);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ss(a, b);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		pa(a, b);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		pb(a, b);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ra(a);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		rb(b);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		rr(a, b);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		rra(a);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		rrb(b);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		rrr(a, b);
	else
		ft_putendl_fd("Error", 2);
}

static void	read_actions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line || *line == '\n')
			break ;
		make_action(a, b, line);
	}
	if (is_sorted(*a) && !stack_size(*b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		a = initialize_stack(ac, av);
		if (a && check_repeats(a))
			read_actions(&a, &b);
	}
	stack_clear(&a, NULL);
	stack_clear(&b, NULL);
	return (0);
}