#include "./libft/libft.h"

void	ft_rra_check(t_list **stack_a)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_a;
	tmp = *stack_a;
	while (last->nxt != NULL)
	{
		tmp = last;
		last = last->nxt;
	}
	last->nxt = *stack_a;
	*stack_a = last;
	tmp->nxt = NULL;
}

void	ft_rrb_check(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	while (last->nxt != NULL)
	{
		tmp = last;
		last = last->nxt;
	}
	last->nxt = *stack_b;
	*stack_b = last;
	tmp->nxt = NULL;
}

void	ft_rrr_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_a;
	tmp = *stack_a;
	while (last->nxt != NULL)
	{
		tmp = last;
		last = last->nxt;
	}
	last->nxt = *stack_a;
	*stack_a = last;
	tmp->nxt = NULL;
	last = *stack_b;
	tmp = *stack_b;
	while (last->nxt != NULL)
	{
		tmp = last;
		last = last->nxt;
	}
	last->nxt = *stack_b;
	*stack_b = last;
	tmp->nxt = NULL;
	return ;
}
