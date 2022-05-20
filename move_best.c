#include "push_swap.h"

void	ft_upa(t_stack **stack_a, t_stack *head_a)
{
	t_stack	*tmp;
	int		size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	if (head_a->index < size / 2)
		while (head_a != *stack_a)
			ft_ra(stack_a);
	else
		while (head_a != *stack_a)
			ft_rra(stack_a);
}

void	ft_upb(t_stack **stack_b, t_stack *head_b)
{
	t_stack	*tmp;
	int		size;

	tmp = *stack_b;
	size = ft_lstsize(*stack_b);
	if (head_b->index < size / 2)
		while (head_b != *stack_b)
			ft_rb(stack_b);
	else
		while (head_b != *stack_b)
			ft_rrb(stack_b);
}

void	ft_fh(t_stack **stack_a, t_stack **stack_b,
	t_stack *head_a, t_stack *head_b)
{	
	int	min;
	int	max;

	max = ft_max(head_a->index, head_b->index);
	min = ft_min(head_a->index, head_b->index);
	while (min--)
		ft_rr(stack_a, stack_b);
	while (head_a != *stack_a)
		ft_ra(stack_a);
	while (head_b != *stack_b)
		ft_rb(stack_b);
}

void	ft_sh(t_stack **stack_a, t_stack **stack_b,
	t_stack *head_a, t_stack *head_b)
{	
	int	min;
	int	max;
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	max = ft_max(size_a - head_a->index, size_b - head_b->index);
	min = ft_min(size_a - head_a->index, size_b - head_b->index);
	while (min--)
		ft_rrr(stack_a, stack_b);
	while (head_a != *stack_a)
		ft_rra(stack_a);
	while (head_b != *stack_b)
		ft_rrb(stack_b);
}

void	ft_up(t_stack **stack_a, t_stack **stack_b,
	t_stack *head_a, t_stack *head_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (head_a->index <= size_a / 2 && head_b->index <= size_b / 2)
		ft_fh(stack_a, stack_b, head_a, head_b);
	else
		ft_sh(stack_a, stack_b, head_a, head_b);
}
