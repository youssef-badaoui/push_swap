/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:21 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/05/21 16:42:23 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack **stack)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			head->index = i++;
			head = head->next;
		}
	}
}

t_stack	*ft_minpair(t_stack *head_a)
{
	t_stack	*tmp;
	int		min;

	min = 2147483647;
	tmp = head_a;
	while (head_a)
	{
		if (head_a->content < min)
			min = head_a->content;
		head_a = head_a->next;
	}
	head_a = tmp;
	while (head_a)
	{
		if (head_a->content == min)
			break ;
		head_a = head_a->next;
	}
	return (head_a);
}

t_stack	*ft_pairing(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tmp;

	tmp = head_a;
	while (head_a)
	{
		if (!head_a->next)
		{
			if (head_a->content < head_b->content
				&& tmp->content > head_b->content)
				return (tmp);
			tmp = ft_minpair(tmp);
			return (tmp);
		}
		if (head_a->content < head_b->content
			&& head_a->next->content > head_b->content)
		{
			head_a = head_a->next;
			break ;
		}
		head_a = head_a->next;
	}
	return (head_a);
}

void	ft_mm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	head_b = *stack_b;
	if (!(*stack_a) || !(*stack_b))
		return ;
	while (head_b)
	{
		head_a = *stack_a;
		head_a = ft_pairing(head_a, head_b);
		if ((head_a->index <= size_a / 2 && head_b->index <= size_b / 2)
			|| (head_a->index >= size_a / 2 && head_b->index >= size_b / 2))
			head_b->mm = ft_max(ft_min(head_a->index, (size_a - head_a->index)),
					ft_min(head_b->index, (size_b - head_b->index)));
		else
			head_b->mm = ft_min(head_a->index, (size_a - head_a->index))
				+ ft_min(head_b->index, (size_b - head_b->index));
		head_b = head_b->next;
	}
}

void	ft_mb(t_stack **stack_b)
{
	t_stack	*head_b;
	int		min;

	min = 500;
	head_b = *stack_b;
	while (head_b)
	{
		if (min > head_b->mm)
				min = head_b->mm;
		head_b = head_b->next;
	}
	head_b = *stack_b;
	while (head_b)
	{
		if (head_b->mm == min)
			head_b->mm = 0;
		head_b = head_b->next;
	}	
}
