/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:14:25 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/17 21:19:40 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Scambia il primo con il secondo nodo
void	ft_swap(t_list **stack)
{
	t_list	*n_0;
	t_list	*n_1;

	n_0 = *stack;
	n_1 = n_0->nxt;
	*stack = n_1;
	n_0->nxt = n_1->nxt;
	n_1->nxt = n_0;
	n_0->bak = n_1;
	n_1->bak = NULL;
	return ;
}

void	ft_sa(t_list **stack_a)
{
	ft_swap(stack_a);
	stack_a = ff(stack_a);
	write (1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	ft_swap(stack_b);
	stack_b = ff(stack_b);
	write (1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write (1, "ss\n", 3);
}

void	ft_which_swap(t_list **stack_a, t_list **stack_b, size_t is_a)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if(ft_lstsize(stack_b) >= 2)
	{
		if((tmp_a->arg > tmp_a->nxt->arg) && (tmp_b->arg > tmp_b->nxt->arg))
			ft_ss(stack_a, stack_b);
		else if(is_a == 1)
			ft_sa(stack_a);
		else
			ft_sb(stack_b);
	}
}
