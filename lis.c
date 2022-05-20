#include "push_swap.h"

void	ft_ml(t_stack **stack_a)
{
	int		maxl;
	int		maxi;
	t_stack	*head;

	maxi = 0;
	maxl = 0;
	head = *stack_a;
	while (head)
	{
		if (maxl <= head->len)
		{
			maxl = head->len;
			maxi = head->index;
		}
		head = head->next;
	}
	test(stack_a, maxl, maxi);
}

void	ft_lis(t_stack **stack_a)
{
	t_stack	*i;
	t_stack	*j;

	i = (*stack_a)->next;
	while (i)
	{
		j = *stack_a;
		while (j != i)
		{
			if (i->content > j->content)
			{
				if (j->len + 1 >= i->len)
				{
					i->prv = j->index;
					i->len = j->len + 1;
				}
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	ft_div(t_stack **stack_a, t_stack **stack_b, int loop)
{
	while (loop-- && ft_lstsize(*stack_a) > 1)
	{
		if ((*stack_a)->len == 600)
			ft_ra(stack_a);
		else
			ft_pb(stack_b, stack_a);
	}
}

void	test(t_stack **stack_a, int maxl, int maxi)
{
	t_stack	*head;
	int		prv;
	int		i;
	int		loop;

	i = 0;
	loop = maxi;
	while (loop--)
	{
		head = *stack_a;
		while (head->index != maxi)
			head = head->next;
		head->len = 600;
		maxi = head->prv;
		if (maxi == -1)
			break ;
	}
	head = *stack_a;
	while (head)
	{
		if (head->len != 600)
			head->len = 0;
		head = head->next;
	}
}
