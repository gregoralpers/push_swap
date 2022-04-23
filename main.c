/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galpers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:38:43 by galpers           #+#    #+#             */
/*   Updated: 2022/04/22 18:36:07 by galpers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

static void sort_big(t_stack **a, t_stack **b)
{
	t_stack *median;

	median = get_pos(*a, stack_size(*a) / 2);

	sort_pos_to_b(a, b, median);
	sort_three(a);
	while (stack_size(*b))
	{
		place_best_top(a, b, get_cheapest_elem(a, b));
		pa(a, b);
	}
	min_top(a, rra);
}

static void	sort(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
	
    a = initialize_stack(ac, av);
    if (a && stack_size(a) > 1 && check_repeats(a))
    {
    	b = NULL;
		if(stack_size(a) <= 3)
			sort_three(&a);
    	else if (stack_size(a) <= 10)
			sort_small(&a, &b);
		else if (!(is_sorted(a)))
			sort_big(&a, &b);
		stack_clear(&a, NULL);
		stack_clear(&b, NULL);
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		sort(ac, av);
	return (0);
}