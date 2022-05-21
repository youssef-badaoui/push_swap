/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:42:11 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/05/21 16:42:13 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_end(t_stack **stack_a)
{
	t_stack	*head_a;
	int		min;
	int		size;
	int		index;

	min = 2147483647;
	size = ft_lstsize(*stack_a);
	head_a = *stack_a;
	while (head_a)
	{
		if (head_a->content < min)
		{
			min = head_a->content;
			index = head_a->index;
		}
		head_a = head_a->next;
	}
	while ((*stack_a)->content != min)
	{
		if (index < size / 2)
			ft_ra(stack_a);
		else if (index >= size / 2)
			ft_rra(stack_a);
	}
}
