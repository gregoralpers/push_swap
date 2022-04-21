#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include ".././libft/libft.h"

typedef struct s_stack
{
		int	content;
		struct s_stack *next;
}	t_stack;

int		is_sorted(t_stack *stack);
t_stack	*get_max(t_stack *a);
t_stack	*get_min(t_stack *a);
void	min_top(t_stack **stack, void func(t_stack **));

void	push(t_stack **s, t_stack *new);
int		pullnumber(t_stack **s);

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
void	sort_small(t_stack **a, t_stack **b);
void	place_best_top(t_stack **a, t_stack **b, t_stack *elem);
int		topr_cost(t_stack *stack, t_stack *elem);
int		toprr_cost(t_stack *stack, t_stack *elem);
t_stack	*element_after_me(t_stack **stack, t_stack *elem);
t_stack	*get_cheapest_elem(t_stack **a, t_stack **b);
t_stack	*get_pos(t_stack *a, int pos);
void	sort_pos_to_b(t_stack **a, t_stack **b, t_stack *target, int len, int num);
void	insert_sorted_b(t_stack **a, t_stack **b);

int		check_repeats(t_stack *stack);
int		check_errors(char *str);

t_stack	*initialize_stack(int ac, char **av);
t_stack	*init_stack_split(char **list);
t_stack	*stack_new(int content);
int		stack_size(t_stack *lst);
t_stack	*stack_last(t_stack *lst);
void	stack_delone(t_stack *lst, int (del)(int));
void	stack_clear(t_stack **lst, int (del)(int));
void	stack_add_front(t_stack **lst, t_stack *new);

#endif