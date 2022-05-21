/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:40 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/05/21 16:42:41 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_upab(t_stack **stack_a, t_stack **stack_b
	, t_stack *head_a, t_stack *head_b)
{
	ft_upa(stack_a, head_a);
	ft_upb(stack_b, head_b);
}

void	ft_fmin(t_stack *head_a, int *min, int *im)
{
	while (head_a)
	{
		if (head_a->content < *min)
		{
			*min = head_a->content;
			*im = head_a->index;
		}
		head_a = head_a->next;
	}
}

void	ft_frrr(t_stack **stack_a, t_stack **stack_b, t_stack **stack)
{
	t_stack	*end;
	t_stack	*head;

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
