#include "./libft/libft.h"
#include "push_swap.h"

void	ft_lst_delete(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (*stack != NULL)
	{
		tmp = (*stack)->nxt;
		ft_free (*stack);
		*stack = tmp;
	}
}

void	ft_lstcheck(t_list *stack_a, int check)
{
	while (stack_a->nxt != NULL)
	{
		if (stack_a->arg == check)
			ft_display_exit();
		stack_a = stack_a->nxt;
	}
	return ;
}

void	ft_lst_order(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->nxt;
	while (tmp2 != NULL)
	{
		if (tmp->arg > tmp2->arg)
			return ;
		tmp = tmp->nxt;
		tmp2 = tmp2->nxt;
	}
	exit(0);
}

void	ft_lst_inverted(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = tmp->nxt;
	while (tmp2 != NULL)
	{
		if (tmp->arg < tmp2->arg)
			return ;
		tmp = tmp->nxt;
		tmp2 = tmp2->nxt;
	}
	ft_sa(stack_a);
	return ;
}

void	ft_conv_ac(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck(*stack_a, tmp->arg);
		i++;
	}
	ft_lst_order(stack_a);
	ft_lst_inverted(stack_a);
	tmp = NULL;
}
