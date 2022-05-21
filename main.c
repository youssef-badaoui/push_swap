/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybadaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:40:38 by ybadaoui          #+#    #+#             */
/*   Updated: 2022/05/21 16:40:39 by ybadaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(long long content, t_stack **stack_a)
{
	t_stack		*new;
	t_stack		*ref;
	static int	i;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->content = content;
	new->next = NULL;
	new->len = 1;
	new->index = i++;
	new->prv = -1;
	new->mm = 0;
	ref = *stack_a;
	if (!ref)
		*stack_a = new;
	else
	{
		while (ref->next)
			ref = ref->next;
		ref->next = new;
	}
}

void	ft_gest(char **av, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (check_space(av[i]))
			ft_gest(ft_split(av[i], ' '), stack_a);
		else
		{
			ft_nd(av[i]);
			add_list(ft_atoi(av[i]), stack_a);
		}
		i++;
	}
}

void	ft_best(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size_a;
	int		size_b;

	head_b = *stack_b;
	head_a = *stack_a;
	size_a = ft_lstsize(head_a);
	size_b = ft_lstsize(head_b);
	while (head_b)
	{
		if (head_b->mm == 0)
		{
			head_a = ft_pairing(head_a, head_b);
			if ((head_a->index >= size_a / 2 && head_b->index >= size_b / 2)
				|| (head_a->index <= size_a / 2 && head_b->index <= size_b / 2))
				ft_up(stack_a, stack_b, head_a, head_b);
			else
				ft_upab(stack_a, stack_b, head_a, head_b);
			ft_pa(stack_a, stack_b);
			break ;
		}
		head_b = head_b->next;
	}
}

void	ft_smart(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		ft_index(stack_a);
		ft_index(stack_b);
		ft_mm(stack_a, stack_b);
		ft_mb(stack_b);
		ft_best(stack_a, stack_b);
	}
	ft_end(stack_a);
}

int	main(int ac, char *av[])
{	
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)ac;
	ft_gest(av + 1, &stack_a);
	if (!stack_a)
		exit(1);
	ft_error(stack_a, av);
	if (ft_sorted(stack_a))
		exit(1);
	if (ft_lstsize(stack_a) < 6)
		ft_shortsort(&stack_a, &stack_b);
	else
	{
		ft_lis(&stack_a);
		ft_ml(&stack_a);
		ft_div(&stack_a, &stack_b, ac - 1);
		ft_smart(&stack_a, &stack_b);
	}
}
