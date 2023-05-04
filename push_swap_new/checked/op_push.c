/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:14 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/16 16:46:39 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Il primo nodo di t_list_1 diventa il primo nodo di t_list_2
void	ft_push(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	tmp = *stack_1;
	*stack_1 = (*stack_1)->nxt;
	(*stack_1)->nxt->bak = NULL;
	tmp->nxt = *stack_2;
	(*stack_2)->bak = tmp;
	*stack_2 = tmp;
	return ;
}

//push first b in a
void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b == NULL)
		return ;
	ft_push(stack_b, stack_a);
	write (1, "pa\n", 3);
}

//push first a in b
void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL)
		return ;
	ft_push(stack_a, stack_b);
	write (1, "pb\n", 3);
}
