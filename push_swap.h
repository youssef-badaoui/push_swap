
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



typedef struct s_stack
{
    long long content;
    struct s_stack *next;
	int index;
	int prv;
	int len;
	int mm;
} t_stack;

typedef struct s_variables {
	int		i;
	int		n;
	int		size;
	int		v_hms;
}	t_variables;



static int	hms(const char *str, char c);
int ft_min(int a, int b);
int ft_max(int a, int b);
static int	s_lent(const char *str, char c);
static int	find_i(const char *s, char c, int n);
static char	*ft_strd(const char *str, char *ptr, int size);
char	**ft_split(char const *s, char c);
int check_space(char *av);
void	ft_putstr(char *s);
long long	ft_atoi(const char *str);
int	ft_lstsize(t_stack *lst);
void	add_list(long long content, t_stack **stack_a);
void ft_gest(char **av, t_stack **stack_a);
void ft_sa(t_stack **stack_a);
void ft_sb(t_stack **stack_b);
void ft_pa(t_stack **stack_a,t_stack **stack_b);
void ft_pb(t_stack **stack_b,t_stack **stack_a);
void ft_ra(t_stack **stack_a);
void ft_rb(t_stack **stack_b);
void ft_rr(t_stack **stack_a, t_stack **stack_b);
void ft_rra(t_stack **stack);
void ft_rrr(t_stack **stack_a, t_stack **stack_b);
void ft_rrb(t_stack **stack);
void test(t_stack **stack_a,int maxl, int maxi);
void ft_ml(t_stack **stack_a);
void ft_lis(t_stack **stack_a);
void ft_div(t_stack **stack_a, t_stack **stack_b,int loop);
void ft_index(t_stack **stack);
t_stack *ft_minpair(t_stack *head_a);
t_stack *ft_pairing(t_stack *head_a, t_stack *head_b);
void ft_mm(t_stack **stack_a, t_stack **stack_b);
void ft_mb(t_stack **stack_b);
void ft_upa(t_stack **stack_a, t_stack *head_a);
void ft_upb(t_stack **stack_b, t_stack *head_b);
void ft_fh(t_stack **stack_a, t_stack **stack_b, t_stack *head_a, t_stack *head_b);
void ft_sh(t_stack **stack_a, t_stack **stack_b, t_stack *head_a, t_stack *head_b);
void ft_up(t_stack **stack_a, t_stack **stack_b, t_stack *head_a, t_stack *head_b);
void ft_best(t_stack **stack_a, t_stack **stack_b);
void ft_end(t_stack **stack_a);
void ft_smart(t_stack **stack_a, t_stack **stack_b);
int ft_dblk(t_stack *stack_a);
int ft_nd(char **av);
void ft_error(t_stack *stack_a, char **av);
int ft_sorted(t_stack *stack_a);
int ft_sortedrev(t_stack *stack_a);
void	ft_sortwo(t_stack **stack_a);
void ft_sortre(t_stack **stack_a, t_stack **stack_b);
void	ft_sortfor(t_stack **stack_a, t_stack **stack_b);
void	ft_sortfive(t_stack **stack_a, t_stack **stack_b);
void	ft_shortsort(t_stack **stack_a, t_stack **stack_b);









