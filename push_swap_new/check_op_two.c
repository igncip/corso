#include "./libft/libft.h"

void	ft_ra_check(t_list **stack_a)
{
	t_list	*last;
	t_list	*first;

	if (*stack_a == NULL || (*stack_a)->nxt == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->nxt != NULL)
		last = last->nxt;
	*stack_a = first->nxt;
	first->nxt = NULL;
	last->nxt = first;
	return ;
}

void	ft_rb_check(t_list **stack_b)
{
	t_list	*last;
	t_list	*first;

	if (*stack_b == NULL || (*stack_b)->nxt == NULL)
		return ;
	last = *stack_b;
	first = *stack_b;
	while (last->nxt != NULL)
		last = last->nxt;
	*stack_b = first->nxt;
	first->nxt = NULL;
	last->nxt = first;
	return ;
}

void	ft_rr_check(t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*first;

	if (*stack_a == NULL || (*stack_a)->nxt == NULL)
		return ;
	last = *stack_a;
	first = *stack_a;
	while (last->nxt != NULL)
		last = last->nxt;
	*stack_a = first->nxt;
	first->nxt = NULL;
	last->nxt = first;
	if (*stack_b == NULL || (*stack_b)->nxt == NULL)
		return ;
	last = *stack_b;
	first = *stack_b;
	while (last->nxt != NULL)
		last = last->nxt;
	*stack_b = first->nxt;
	first->nxt = NULL;
	last->nxt = first;
	return ;
}
