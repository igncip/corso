#include "./libft/libft.h"
#include "push_swap.h"

void	ft_order_three(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		k;

	i = (*stack_a)->arg;
	j = (*stack_a)->nxt->arg;
	k = (*stack_a)->nxt->nxt->arg;
	if ((i < k && k < j) || (j < i && i < k) || (k < j && j < i))
		ft_which_swap(stack_a, stack_b, 1);
	if (k < i && i < j)
		ft_ra(stack_a);
	if (j < k && k < i)
		ft_rra(stack_a);
	return ;
}

void	ft_order_five(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;

	i = size - 3;
	while (i-- > 0)
		ft_pb(stack_a, stack_b);
	ft_order_three(stack_a, stack_b);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, ft_lstsize(*stack_a));
}

void	ft_move_to_a(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size_a;
	int	size_b;

	i = 0;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	while (*stack_b != NULL)
	{
		i = ft_best_nbr_b(stack_b, size_b, stack_a, size_a);
		if (i < 0)
			while (i++ < 0)
				ft_rrb(stack_b);
		else if (i > 0)
			while (i-- > 0)
				ft_rb(stack_b);
		ft_pa(stack_b, stack_a);
		size_a++;
		size_b--;
	}
}

void	ft_move_to_b(t_list **stack_a, t_list **stack_b, int *arr, int max)
{
	int	i;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	i = ft_best_nbr_a(*stack_a, size_a, arr, max);
	while (i != -1)
	{
		if (i > 0)
		{
			while (i-- > 0)
				ft_ra(stack_a);
		}
		ft_pb(stack_a, stack_b);
		i = ft_best_nbr_a(*stack_a, --size_a, arr, max);
	}
}
