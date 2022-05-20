#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

	ft_putstr("sa\n");
	if ((*stack_a)->next)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	ft_sb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*head;

	ft_putstr("sa\n");
	if ((*stack_b)->next)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_b)->next->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_b;
	t_stack	*tmp_b;

	ft_putstr("pa\n");
	head_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = head_b;
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	t_stack		*head_a;
	static int	i;

	ft_putstr("pb\n");
	if (*stack_a)
	{
		head_a = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = head_a;
	}
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*head_a;
	t_stack	*hn_a;

	ft_putstr("ra\n");
	head_a = (*stack_a);
	hn_a = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head_a;
	(*stack_a)->next->next = NULL;
	*stack_a = hn_a;
}
