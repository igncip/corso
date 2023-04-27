#include "./libft/libft.h"

void	ft_sa_check(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->nxt;
	*stack_a = tmp2;
	tmp->nxt = tmp2->nxt;
	tmp2->nxt = tmp;
	return ;
}

void	ft_sb_check(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_b;
	tmp2 = tmp->nxt;
	*stack_b = tmp2;
	tmp->nxt = tmp2->nxt;
	tmp2->nxt = tmp;
	return ;
}

void	ft_ss_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->nxt;
	*stack_a = tmp2;
	tmp->nxt = tmp2->nxt;
	tmp2->nxt = tmp;
	tmp = NULL;
	tmp2 = NULL;
	tmp = *stack_b;
	tmp2 = tmp->nxt;
	*stack_b = tmp2;
	tmp->nxt = tmp2->nxt;
	tmp2->nxt = tmp;
	return ;
}

void	ft_pa_check(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->nxt;
	tmp->nxt = *stack_a;
	*stack_a = tmp;
	return ;
}

void	ft_pb_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->nxt;
	tmp->nxt = *stack_b;
	*stack_b = tmp;
	return ;
}
