
#include "push_swap.h"

int ft_min(int a, int b)
{
	if(a < b)
		return (a);
	else
		return (b);
}

int ft_max(int a, int b)
{
	if(a > b)
		return (a);
	else
		return (b);
}

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

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	j;
	long long	nb;

	i = 0;
	j = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		||str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 43)
			j = 1;
		else
			j = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * j);
}

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

void	add_list(long long content, t_stack **stack_a)
{
	t_stack *new;
	t_stack *ref;
	static int i;

	new = malloc(sizeof(t_stack));
	if(!new)
		return ;
	new->content = content;
	new->next = NULL;
	new->len = 1;
	new->index = i++;
	new->prv = -1;
	new->mm = 0;
	ref = *stack_a;
	if(!ref)
		*stack_a = new;
	else
	{
		while (ref->next)
			ref = ref->next;
		ref->next = new;
	}
}

void ft_gest(char **av, t_stack **stack_a)
{
	int i;

	i = 1;
	while(av[i])
	{
		if(check_space(av[i]))
			ft_gest(ft_split(av[i], ' '), stack_a);
		else
			add_list(ft_atoi(av[i]), stack_a);
		i++;
	}
}

void ft_upa(t_stack **stack_a, t_stack *head_a)
{
	t_stack *tmp;
	int size;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	if(head_a->index < size/2)
		while(head_a != *stack_a)
			ft_ra(stack_a);
	else
		while(head_a != *stack_a)
			ft_rra(stack_a);
}

void ft_upb(t_stack **stack_b, t_stack *head_b)
{
	t_stack *tmp;
	int size;

	tmp = *stack_b;
	size = ft_lstsize(*stack_b);
	if(head_b->index < size/2)
		while(head_b != *stack_b)
			ft_rb(stack_b);
	else
		while(head_b != *stack_b)
			ft_rrb(stack_b);
}

void ft_fh(t_stack **stack_a, t_stack **stack_b, t_stack *head_a, t_stack *head_b)
{	
	int min;
	int max;

	max = ft_max(head_a->index, head_b->index);
		min = ft_min(head_a->index, head_b->index);
		while(min--)
			ft_rr(stack_a, stack_b);
		while(head_a != *stack_a)
			ft_ra(stack_a);
		while(head_b != *stack_b)
			ft_rb(stack_b);
}

void ft_sh(t_stack **stack_a, t_stack **stack_b, t_stack *head_a, t_stack *head_b)
{	
	int min;
	int max;
	int size_a;
	int size_b; 
	
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	max = ft_max(size_a - head_a->index, size_b - head_b->index);
	min = ft_min(size_a - head_a->index, size_b - head_b->index);
	while(min--)
		ft_rrr(stack_a, stack_b);
	while(head_a != *stack_a)
		ft_rra(stack_a);
	while(head_b != *stack_b)
		ft_rrb(stack_b);
}

void ft_up(t_stack **stack_a, t_stack **stack_b, t_stack *head_a, t_stack *head_b)
{
	int size_a;
	int size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if(head_a->index <= size_a/2 && head_b->index <= size_b/2)
		ft_fh(stack_a, stack_b, head_a, head_b);
	else
		ft_sh(stack_a, stack_b, head_a,head_b);
}

void ft_best(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;
	t_stack *head_b;
	int size_a;
	int size_b;

	head_b = *stack_b;
	head_a = *stack_a;
	size_a = ft_lstsize(head_a);
	size_b = ft_lstsize(head_b);
	
	while(head_b)
	{
		if(head_b->mm == 0)
		{
			head_a = ft_pairing(head_a, head_b);
			if((head_a->index >= size_a/2 && head_b->index >= size_b/2) || (head_a->index <= size_a/2 && head_b->index <= size_b/2))
			{
				ft_up(stack_a, stack_b, head_a, head_b);
			}
			else
			{
				ft_upa(stack_a, head_a);
				ft_upb(stack_b, head_b);
			}
			ft_pa(stack_a, stack_b);
			break;
		}
		head_b = head_b->next;
	}
}

void ft_end(t_stack **stack_a)
{
	t_stack *head_a;
	int min;
	int size;
	int index;

	min = 2147483647;
	size = ft_lstsize(*stack_a);
	head_a = *stack_a;
	while(head_a)
	{
		if(head_a->content < min)
		{
			min = head_a->content;
			index = head_a->index;
		}
		head_a = head_a->next;
	}
	while((*stack_a)->content != min)
	{

		if(index < size/2)
			ft_ra(stack_a);
		else if(index >= size/2)
			ft_rra(stack_a);
	}
}

void ft_smart(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;
	t_stack *head_b;

	while(*stack_b)
	{
		ft_index(stack_a);
		ft_index(stack_b);
		ft_mm(stack_a, stack_b);
		ft_mb(stack_b);
		ft_best(stack_a,stack_b);
	}
	ft_end(stack_a);
}

int main(int ac, char *av[])
{	
	t_stack *stack_a;
	t_stack *stack_b;
	ft_gest(av, &stack_a);
	/*this will protect all the upcoming fonctions*/
	if(!stack_a)
		exit(1);
	ft_error(stack_a, av);
	if(ft_sorted(stack_a))
		exit(1);
	if((ac - 1) < 6) 
		ft_shortsort(&stack_a, &stack_b);
	else
	{
		ft_lis(&stack_a);
		ft_ml(&stack_a);
		ft_div(&stack_a, &stack_b, ac - 1);
		ft_smart(&stack_a,&stack_b);
	}
}


