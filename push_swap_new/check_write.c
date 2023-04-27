#include "push_swap.h"

static void	ft_lstcheck_c(t_list *stack_a, int check)
{
	while (stack_a->nxt != NULL)
	{
		if (stack_a->arg == check)
			ft_display_exit();
		stack_a = stack_a->nxt;
	}
	return ;
}

static void	ft_lst_order_c(t_list **stack_a)
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

void	ft_check_lst_inverted(t_list **stack_a)
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
	ft_sa_check(stack_a);
	return ;
}

void	ft_check_write_lst(t_list **stack_a, int argc, char **argv, int i)
{
	t_list	*tmp;

	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, tmp);
		ft_lstcheck_c(*stack_a, tmp->arg);
		i++;
	}
	ft_lst_order_c(stack_a);
	ft_check_lst_inverted(stack_a);
	tmp = NULL;
}
