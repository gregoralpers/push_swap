#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*b) > 0)
	{
		push(a, ft_lstnew(pullnumber(b)));
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 0)
	{
		push(b, ft_lstnew(pullnumber(a)));
		write(1, "pb\n", 3);
	}
}

void	push(t_stack **s, t_stack *new)
{
	if (s == NULL)
		return ;
	ft_lstadd_front(s, new);
}

int	*pullnumber(t_stack **s)
{
	int		*content;
	t_stack	*pulledlist;

	if (*s == NULL || s == NULL)
		return (NULL);
	pulledlist = *s;
	*s = pulledlist->next;
	content = pulledlist->content;
	ft_lstdelone(pulledlist, NULL);
	return (content);
}
