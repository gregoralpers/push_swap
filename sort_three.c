#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (get_max(*stack)->next == NULL)
	{
		if ((int)((*stack)->content) < (int)((*stack)->next->content))
			return ;
		else
		{
			sa(stack);
			return ;
		}
	}
	else if (get_max(*stack) == *stack)
	{
		ra(stack);
		sort_three(stack);
	}
	else
	{
		rra(stack);
		sort_three(stack);
	}
}
