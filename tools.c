#include "push_swap.h"

int check_space(char *av)
{
	int i;

	i = 0;
	while(av[i])
	{
		if(av[i] == ' ')
			return (1);
		i++; 
	}
	return (0);
}

int ft_nd(char **av)
{
	int i;
	int j;

	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if(av[i][j] < 0 || av[i][j] > 9)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void ft_gest(char **av, t_stack *stack_a)
{
	int i;

	i = 0;
	while(av[i])
	{
		if(check_space(av[i]))
			ft_gest(split(av[i]));
		else
			list_add(ft_atoi(av[i]), &stack_a);
		i++;
	}
}

void	list_add(int content, t_stack **a)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if(!new)
		return ;
	new->content = content;
	new->next = NULL;
	while (a->next)
		a = a->next;
	a->next = new;
}