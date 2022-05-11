#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

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

char	**ft_split(char const *s, char c);
void	list_add(int content, t_stack **a);
void ft_gest(char **av, t_stack *stack_a);
int ft_nd(char **av);
int check_space(char *av);




