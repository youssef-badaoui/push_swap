
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



typedef struct s_stack
{
    int content;
    struct s_stack *next;
	int index;
	int prv;
	int len;
} t_stack;

typedef struct s_variables {
	int		i;
	int		n;
	int		size;
	int		v_hms;
}	t_variables;

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

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	nb;

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

void	add_list(int content, t_stack **stack_a)
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

	printf("%p\n", stack_a);
	if((*stack_a)->next)	
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	printf("%p\n", stack_a);
}

void ft_pa(t_stack **stack_a,t_stack **stack_b)
{
	t_stack *head_b;
	t_stack *tmp_b;

	ft_putstr("pa");
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
void ft_ra(t_stack **stack)
{
	t_stack *head;
	t_stack *hn;

	ft_putstr("ra\n");
	head = (*stack);
	hn = (*stack)->next;
	while((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = head;
	(*stack)->next->next = NULL; 

	*stack = hn;
}

void ft_rra(t_stack **stack)
{
	t_stack *end;
	t_stack *head;

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
	while(loop--)
	{
		if((*stack_a)->len == 600)
			ft_ra(stack_a);
		else
			ft_pb(stack_b, stack_a);
	}
}

int main(int ac, char *av[])
{	
	t_stack *stack_a;
	t_stack *stack_b;

	if(ft_nd(av))
	{
		//error
	}
	ft_gest(av, &stack_a);
	ft_lis(&stack_a);
	ft_ml(&stack_a);
	ft_div(&stack_a, &stack_b, ac - 1);
	ft_smart();


	printf("stack a:\n");
	while(stack_a)
	{
		printf("->%d", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\nstack b:\n");
	while(stack_b)
	{
		printf("->%d", stack_b->content);
		stack_b = stack_b->next;
	}
}
void ft_smart(t_stack **stack_a, t_stack **stack_b)
{
	
}