#include "includes/push_swap.h"

static void sort_big(t_stack **a, t_stack **b, int iterations)
{
	t_stack *target;
	int	i;
	int num;
	int total;

	i = 1;
	while (i < iterations)
	{
		num = stack_size(*a) / 2;
		target = get_pos(*a, num);
		total = stack_size(*a);
		sort_pos_to_b(a, b, target, total, total - num);
		i++;
	}
	while (stack_size(*b))
	{
		place_best_top(a, b, get_cheapest_elem(a, b));
		pa(a, b);
	}
	while (!(is_sorted(*a)))
		sort_small(a, b);
}

static void	sort(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
	int i;
	int	iterations;

    a = initialize_stack(ac, av);
    if (a && stack_size(a) > 1 && check_repeats(a))
    {
    	b = NULL;
		if(stack_size(a) <= 3)
			sort_three(&a);
    	else if (stack_size(a) <= 10)
			sort_small(&a, &b)
			;
		else if (!(is_sorted(a)))
		{
			i =stack_size(a);
			iterations = 2;
			while (i / 2 != 0)
			{
				i = i / 2;
				iterations++;
			}
			sort_big(&a, &b, iterations);
		}
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