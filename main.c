
#include "push_swap.h"

static int	hms(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (str[0] == 0)
		return (0);
	if (str[0] != c)
		count ++;
	while (str[i])
	{
		if (str[i] != c)
			if (str[i - 1] == c)
				count ++;
		i++;
	}
	return (count);
}

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

static int	s_lent(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	find_i(const char *s, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (s[0] != c)
	{
		if (n == 0)
			return (0);
		i++;
	}
	while (s[j])
	{
		if (s[j] != c && s[j - 1] == c)
		{
			if (n == i)
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

static char	*ft_strd(const char *str, char *ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	t_variables	vr;
	char		**str;

	if (!s)
		return (0);
	vr.v_hms = hms((char *)s, c);
	vr.i = -1;
	str = (char **)malloc((sizeof(char *) * (vr.v_hms + 1)));
	if (!str)
		return (0);
	while (++(vr.i) < vr.v_hms)
	{
		vr.n = find_i(s, c, vr.i);
		vr.size = s_lent(s + (vr.n), c);
		str[vr.i] = malloc(1 * (vr.size +1));
		if (!str[vr.i])
		{
			while (--(vr.i) >= 0)
				free(str[(vr.i)]);
			return (free(str), NULL);
		}
		ft_strd(s + (vr.n), str[vr.i], vr.size);
	}
	str[vr.i] = NULL;
	return (str);
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

void ft_sa(t_stack **stack_a)
{
	t_stack *tmp;
	t_stack *head;
	ft_putstr("sa\n");
	if((*stack_a)->next)	
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void ft_sb(t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *head;
	ft_putstr("sa\n");
	if((*stack_b)->next)	
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = (*stack_b)->next->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void ft_pa(t_stack **stack_a,t_stack **stack_b)
{
	t_stack *head_b;
	t_stack *tmp_b;

	ft_putstr("pa\n");
	head_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = head_b;
}

void ft_pb(t_stack **stack_b,t_stack **stack_a)
{
	t_stack *head_a;
	static int i;

	ft_putstr("pb\n");
	if(*stack_a)
	{
		head_a = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = head_a;
	}
}

void ft_ra(t_stack **stack_a)
{
	t_stack *head_a;
	t_stack *hn_a;

	ft_putstr("ra\n");
	head_a = (*stack_a);
	hn_a = (*stack_a)->next;
	while((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head_a;
	(*stack_a)->next->next = NULL; 

	*stack_a = hn_a;
}

void ft_rb(t_stack **stack_b)
{
	t_stack *head_b;
	t_stack *hn;

	ft_putstr("rb\n");
	head_b = (*stack_b);
	hn = (*stack_b)->next;
	while((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = head_b;
	(*stack_b)->next->next = NULL; 
	 *stack_b = hn;
}

void ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;
	t_stack *hn_a;
	t_stack *head_b;
	t_stack *hn;

	ft_putstr("rr\n");
	head_a = (*stack_a);
	hn_a = (*stack_a)->next;
	while((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head_a;
	(*stack_a)->next->next = NULL; 
	*stack_a = hn_a;
	head_b = (*stack_b);
	hn = (*stack_b)->next;
	while((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = head_b;
	(*stack_b)->next->next = NULL; 
	 *stack_b = hn;
}

void ft_rra(t_stack **stack)
{
	t_stack *end;
	t_stack *head;

	ft_putstr("rra\n");
	head = *stack;
	while((*stack)->next->next)
		*stack = (*stack)->next;
	end = *stack;
	*stack = (*stack)->next;
	end->next = NULL;
	(*stack)->next = head;
}

void ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *end;
	t_stack *head;
	t_stack **stack;

	ft_putstr("rrr\n");
	if(ft_lstsize(*stack_a) > 1)
	{
		stack = stack_a;
		head = *stack;
		while((*stack)->next->next)
			*stack = (*stack)->next;
		end = *stack;
		*stack = (*stack)->next;
		end->next = NULL;
		(*stack)->next = head;
	}
	if(ft_lstsize(*stack_b) > 1)
	{
		stack = stack_b;
		head = *stack;
		while((*stack)->next->next)
			*stack = (*stack)->next;
		end = *stack;
		*stack = (*stack)->next;
		end->next = NULL;
		(*stack)->next = head;
	}
}

void ft_rrb(t_stack **stack)
{
	t_stack *end;
	t_stack *head;

	ft_putstr("rrb\n");
	head = *stack;
	while((*stack)->next->next)
		*stack = (*stack)->next;
	end = *stack;
	*stack = (*stack)->next;
	end->next = NULL;
	(*stack)->next = head;
}

void test(t_stack **stack_a,int maxl, int maxi)
{
	t_stack *head;
	int	prv;
	int i;
	int loop;

	i = 0;
	loop = maxi;
	while(loop--)
	{
		head = *stack_a;
		while(head->index != maxi)
			head = head->next;
		head->len = 600;
		maxi = head->prv;
		if(maxi == -1)
			break;
	}
	head = *stack_a;
	while(head)
	{
		if(head->len != 600)
			head->len = 0;
		head = head->next;
	}
}

void ft_ml(t_stack **stack_a)
{
	int maxl;
	int maxi;
	t_stack *head;

	maxi = 0;
	maxl = 0;
	head = *stack_a;
	while(head)
	{
		if(maxl <= head->len)
		{
			maxl = head->len;
			maxi = head->index;
		}
		head = head->next;
	}
	test(stack_a, maxl, maxi);
}

void ft_lis(t_stack **stack_a)
{
	t_stack *i;
	t_stack *j;

	i = (*stack_a)->next;
	while(i)
	{
		j = *stack_a;
		while(j != i)
		{
			if(i->content > j->content)
			{
				if(j->len+1 >= i->len)
				{
					i->prv = j->index;
					i->len = j->len+1;
				}
			}
			j = j->next;
		}
		i = i->next;
	}
}

void ft_div(t_stack **stack_a, t_stack **stack_b,int loop)
{
	while(loop-- && ft_lstsize(*stack_a) > 1)
	{
		if((*stack_a)->len == 600)
			ft_ra(stack_a);
		else
			ft_pb(stack_b, stack_a);
	}
}

void ft_index(t_stack **stack)
{
	t_stack *head;
	int i;

	i = 0;
	head = *stack;
	if(head)
		while(head)
		{
			head->index = i++;
			head = head->next;
		}
}

t_stack *ft_minpair(t_stack *head_a)
{
	t_stack *tmp;
	int min;

	min = 2147483647;
	tmp = head_a;
	while(head_a)
	{
		if(head_a->content < min)
			min = head_a->content;
		head_a = head_a->next;
	}
	head_a = tmp;
	while(head_a)
	{
		if(head_a->content == min)
			break;
		head_a = head_a->next;
	}
	return (head_a);
}

t_stack *ft_pairing(t_stack *head_a, t_stack *head_b)
{
	t_stack *tmp;

	tmp = head_a;
	while(head_a)
	{
		if(!head_a->next)
		{
			if(head_a->content < head_b->content && tmp->content > head_b->content)
				return (tmp);
			tmp = ft_minpair(tmp);
			return(tmp);
		}
		if(head_a->content < head_b->content && head_a->next->content > head_b->content)
		{
			head_a = head_a->next;
			break;
		}
		head_a = head_a->next;
	}
	return (head_a);
}

void ft_mm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;
	t_stack *head_b;
	int size_a;
	int size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	head_b = *stack_b;
	if(!(*stack_a) || !(*stack_b))
		return;
	while(head_b)
	{
		head_a = *stack_a;
		head_a = ft_pairing(head_a, head_b);

		if((head_a->index <= size_a/2 && head_b->index <= size_b/2) || (head_a->index >= size_a/2 && head_b->index >= size_b/2))
			head_b->mm = ft_max(ft_min(head_a->index, (size_a - head_a->index)), ft_min(head_b->index, (size_b - head_b->index)));
		else
			head_b->mm = ft_min(head_a->index, (size_a - head_a->index)) + ft_min(head_b->index, (size_b - head_b->index));
		head_b = head_b->next;
	}
}

void ft_mb(t_stack **stack_b)
{
	t_stack *head_b;
	int min;

	min = 500;
	head_b = *stack_b;
	while(head_b)
	{
		if(min > head_b->mm)
				min = head_b->mm;
		head_b = head_b->next;
	}
	head_b = *stack_b;
	while (head_b)
	{
		if(head_b->mm == min)
			head_b->mm = 0;
		head_b = head_b->next;
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

int ft_dblk(t_stack *stack_a)
{
	t_stack *head_a;
	while(stack_a)
	{
		head_a = stack_a->next;
		while(head_a)
		{
			if(head_a->content == stack_a->content)
				return (1);
			head_a = head_a->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int ft_nd(char **av)
{
	int i;
	int j;

	i = 0;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if(av[i][j] < '0' || av[i][j] > '9')
			{
				if(av[i][j] == '-' && j == 0);
				else
					return(1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void ft_error(t_stack *stack_a, char **av)
{
	t_stack *head_a;

	head_a = stack_a;
	if(ft_dblk(head_a) || ft_nd(av + 1))
	{
		ft_putstr("error\n");
		exit(1);
	}

	while(stack_a)
	{
		if(stack_a->content > 2147483647 || stack_a->content < -2147483648)
		{
			ft_putstr("error\n");
			exit(1);
		}
		stack_a = stack_a->next;
	}
}

int ft_sorted(t_stack *stack_a)
{
	while(stack_a->next)
	{
		if(stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int ft_sortedrev(t_stack *stack_a)
{
	while(stack_a->next)
	{
		if(stack_a->content < stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_sortwo(t_stack **stack_a)
{
	if((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void ft_sortre(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;
	int min;
	int im;

	min = 2147483647;
	head_a = *stack_a;
	ft_index(stack_a);
	while(head_a)
	{
		if(head_a->content < min)
		{
			min = head_a->content;
			im = head_a->index;
		}
		head_a = head_a->next;
	}
	if(im == 0)
	{
		ft_pb(stack_b, stack_a);
		ft_sortwo(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else if(im == 1)
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
	t_stack *head_a;
	int min;
	int im;

	min = 2147483647;
	head_a = *stack_a;
	while(head_a)
	{
		if(head_a->content < min)
		{
			min = head_a->content;
			im = head_a->index;
		}
		head_a = head_a->next;
	}
	if(im < 2)
		while((*stack_a)->content != min)
			ft_ra(stack_a);
	else
		while((*stack_a)->content != min)
			ft_rra(stack_a);
	ft_pb(stack_b, stack_a);
	ft_sortre(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sortfive(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;
	int min;
	int im;
	int i;

	i = 2;
	while(i--)
	{
		min = 2147483647;
		head_a = *stack_a;
		while(head_a)
		{
			if(head_a->content < min)
			{
				min = head_a->content;
				im = head_a->index;
			}
			head_a = head_a->next;
		}
		if(im <= 2)
			while((*stack_a)->content != min)
				ft_ra(stack_a);
		else
			while((*stack_a)->content != min)
				ft_rra(stack_a);
		ft_pb(stack_b, stack_a);
	}
	ft_sortre(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_shortsort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *head_a;

	head_a = *stack_a;
	if(ft_lstsize(*stack_a) == 3)
		ft_sortre(stack_a, stack_b);
	else if(ft_lstsize(*stack_a) == 5)
		ft_sortfive(stack_a, stack_b);
	else if(ft_lstsize(*stack_a) == 2)
		ft_sortwo(stack_a);
	else if(ft_lstsize(*stack_a) == 4)
		ft_sortfor(stack_a, stack_b);
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


