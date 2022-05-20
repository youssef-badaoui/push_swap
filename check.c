#include "push_swap.h"

void	ft_error(t_stack *stack_a, char **av)
{
	t_stack	*head_a;

	head_a = stack_a;
	if (ft_dblk(head_a) || ft_nd(av + 1))
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

int	ft_nd(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				if (av[i][j] == '-' && j == 0)
					;
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
