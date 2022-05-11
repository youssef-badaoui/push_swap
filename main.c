
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



typedef struct s_stack
{
    int content;
    struct s_stack *next;
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

	new = malloc(sizeof(t_stack));
	if(!new)
		return ;
	new->content = content;
	new->next = NULL;
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
int main(int ac, char *av[])
{	
	t_stack *stack_a = NULL;
	t_stack *stack_b;

	if(ft_nd(av))
	{
		//error
	}
	ft_gest(av, &stack_a);
	int i = 0;
	printf("ok\n");
	while(stack_a)
	{
		printf("->%d", stack_a->content);
		stack_a = stack_a->next;
	}
}