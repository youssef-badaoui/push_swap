#include "push_swap.h"

void	ft_rb(t_stack **stack_b)
{
	t_stack	*head_b;
	t_stack	*hn;

	ft_putstr("rb\n");
	head_b = (*stack_b);
	hn = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = head_b;
	(*stack_b)->next->next = NULL;
	*stack_b = hn;
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*hn_a;
	t_stack	*head_b;
	t_stack	*hn;

	ft_putstr("rr\n");
	head_a = (*stack_a);
	hn_a = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head_a;
	(*stack_a)->next->next = NULL;
	*stack_a = hn_a;
	head_b = (*stack_b);
	hn = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = head_b;
	(*stack_b)->next->next = NULL;
	*stack_b = hn;
}

void	ft_rra(t_stack **stack)
{
	t_stack	*end;
	t_stack	*head;

	ft_putstr("rra\n");
	head = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end = *stack;
	*stack = (*stack)->next;
	end->next = NULL;
	(*stack)->next = head;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*end;
	t_stack	*head;
	t_stack	**stack;

	ft_putstr("rrr\n");
	if (ft_lstsize(*stack_a) > 1)
	{
		stack = stack_a;
		head = *stack;
		while ((*stack)->next->next)
			*stack = (*stack)->next;
		end = *stack;
		*stack = (*stack)->next;
		end->next = NULL;
		(*stack)->next = head;
	}
	if (ft_lstsize(*stack_b) > 1)
	{
		stack = stack_b;
		head = *stack;
		while ((*stack)->next->next)
			*stack = (*stack)->next;
		end = *stack;
		*stack = (*stack)->next;
		end->next = NULL;
		(*stack)->next = head;
	}
}

void	ft_rrb(t_stack **stack)
{
	t_stack	*end;
	t_stack	*head;

	ft_putstr("rrb\n");
	head = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end = *stack;
	*stack = (*stack)->next;
	end->next = NULL;
	(*stack)->next = head;
}
