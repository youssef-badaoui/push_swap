/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:49 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/05/21 16:42:51 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortwo(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void	ft_sortre(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		min;
	int		im;

	min = 2147483647;
	head_a = *stack_a;
	ft_index(stack_a);
	ft_fmin(head_a, &min, &im);
	if (im == 0)
	{
		ft_pb(stack_b, stack_a);
		ft_sortwo(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else if (im == 1)
	{
		ft_rra(stack_a);
		ft_sortwo(stack_a);
		ft_rra(stack_a);
	}
	else
	{
		ft_sortwo(stack_a);
		ft_rra(stack_a);
	}
}

void	ft_sortfor(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		min;
	int		im;

	min = 2147483647;
	head_a = *stack_a;
	while (head_a)
	{
		if (head_a->content < min)
		{
			min = head_a->content;
			im = head_a->index;
		}
		head_a = head_a->next;
	}
	if (im < 2)
		while ((*stack_a)->content != min)
			ft_ra(stack_a);
	else
		while ((*stack_a)->content != min)
			ft_rra(stack_a);
	ft_pb(stack_b, stack_a);
	ft_sortre(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sortfive(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		min;
	int		im;
	int		i;

	i = 2;
	while (i--)
	{
		min = 2147483647;
		head_a = *stack_a;
		ft_fmin(head_a, &min, &im);
		if (im <= 2)
			while ((*stack_a)->content != min)
				ft_ra(stack_a);
		else
			while ((*stack_a)->content != min)
				ft_rra(stack_a);
		ft_pb(stack_b, stack_a);
	}
	ft_sortre(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_shortsort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;

	head_a = *stack_a;
	if (ft_lstsize(*stack_a) == 3)
		ft_sortre(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		ft_sortfive(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 2)
		ft_sortwo(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		ft_sortfor(stack_a, stack_b);
}
