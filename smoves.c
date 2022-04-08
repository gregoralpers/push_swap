#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	second = (*stack)->next;
	third = second->next;
	*stack = second;
	second->next = first;
	first->next = third;
}

void	sa(t_stack **a)
{
	if (ft_lstsize(*a) > 1)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b)
{
	if (ft_lstsize(*b) > 1)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 1)
		swap(a);
	if (ft_lstsize(*b) > 1)
		swap(b);
	write(1, "ss\n", 3);
}