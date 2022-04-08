#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include "libft/libft.h"

typedef t_list	t_stack;

int		get_mean(t_stack *stack);
int		is_sorted(t_stack *stack);
t_stack	*get_max(t_stack *a);
t_stack	*get_min(t_stack *a);
void	min_top(t_stack **stack, void func(t_stack **));

void	push(t_stack **s, t_stack *new);
int	*pullnumber(t_stack **s);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack);

#endif