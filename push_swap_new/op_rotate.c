/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:18 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/17 19:39:28 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Primo diventa ultimo
void	ft_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (*stack == NULL || (*stack)->nxt == NULL)
		return ;
	last = *stack;
	first = *stack;
	while (last->nxt != NULL)
		last = last->nxt;
	*stack = first->nxt;
	first->nxt = NULL;
	last->nxt = first;
	first->bak = last->bak;
	(*stack)->bak = NULL;
	return ;
}

void	ft_ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	write (1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	write (1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write (1, "rr\n", 3);
}
