#include "includes/push_swap.h"

static void	sort(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = initialize_stack(ac, av);
    if (a && stack_size(a) > 1 && check_repeats(a))
    {
    	b = NULL;
        if (stack_size(a) <= 3)
        	sort_three(&a);
		else if (stack_size(a) <= 10)
			sort_small(&a, &b);
		else
		{
			sort_mean_to_b(&a, &b, stack_size(a), get_mean(a));
			while (stack_size(b))
			{
				place_best_top(&a, &b, get_cheapest_elem(&a, &b));
				pa(&a, &b);
			}
			while (!(is_sorted(a)))
				sort_small(&a, &b);
        }
        stack_clear(&a, NULL);
		stack_clear(&b, NULL);
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		sort(ac, av);
	}
	return (0);
}