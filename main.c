#include "push_swap.h"

static void    sort(int ac, char **av)
{
        t_stack *a;
        t_stack *b;

        a = initialize_stack(ac, av, 0);
        if (a && ft_lstsize(a) > 1 && check_repeats(a, 0))
        {
            b = NULL;
            if (ft_lst_size (a) <= 3)
                sort_three(&a);
        }
        ft_lstclear(&a, NULL);
        ft_lstclear(&b, NULL);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		sort(ac, av);
	}
	return (0);
}