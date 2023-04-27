#include "./libft/libft.h"
#include "push_swap.h"

void	ft_which_order(t_list **stack_a, t_list **stack_b, int size)
{
	int	*dst;
	int	*arr;
	int	i;

	i = 0;
	if (size == 3)
	{
		ft_order_three(stack_a);
		return ;
	}
	if (size == 5)
	{
		ft_order_five(stack_a, stack_b);
		return ;
	}
	dst = ft_copy_cont(*stack_a, size);
	arr = ft_define_lis(dst, size, &i);
	ft_move_to_b(stack_a, stack_b, arr, i);
	ft_move_to_a(stack_a, stack_b);
	ft_search_min(stack_a, size);
	free (dst);
	free (arr);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**arg;

	stack_a = NULL;
	stack_b = NULL;
	arg = NULL;
	size = 0;
	ft_conv_ac(stack_a, argc, argv, 1);
	size = ft_lstsize(stack_a);
	if (size == 2)
		return (0);
	ft_which_order(&stack_a, &stack_b, size);
	ft_lst_delete(&stack_a);
	ft_lst_delete(&stack_b);
	return (0);
}
