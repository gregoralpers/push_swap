#include "includes/push_swap.h"

static void	revrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	if (temp && stack_size(*stack) > 1)
	{
		last = stack_last(*stack);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rra(t_stack **a)
{
	if (stack_size(*a) > 1)
	{
		revrotate(a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b)
{
	if (stack_size(*b) > 1)
	{	
		revrotate(b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	revrotate(a);
	revrotate(b);
	write(1, "rrr\n", 4);
}
