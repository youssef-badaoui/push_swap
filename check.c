/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:40:30 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/05/21 16:40:32 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack_a, char **av)
{
	t_stack	*head_a;

	head_a = stack_a;
	(void)av;
	if (ft_dblk(head_a))
	{
		ft_putstr("error\n");
		exit(1);
	}
	while (stack_a)
	{
		if (stack_a->content > 2147483647 || stack_a->content < -2147483648)
		{
			ft_putstr("error\n");
			exit(1);
		}
		stack_a = stack_a->next;
	}
}

int	ft_dblk(t_stack *stack_a)
{
	t_stack	*head_a;

	while (stack_a)
	{
		head_a = stack_a->next;
		while (head_a)
		{
			if (head_a->content == stack_a->content)
				return (1);
			head_a = head_a->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_nd(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
		{
			if (av[i] == '-' && i == 0)
				;
			else
			{
				ft_putstr("error\n");
				exit(1);
			}
		}
		i++;
	}
}

int	ft_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	ft_sortedrev(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content < stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
