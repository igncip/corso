/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:10 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/17 19:21:55 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Ultimo diventa primo
void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack;
	tmp = *stack;
	while (last->nxt != NULL)
	{
		tmp = last;
		last = last->nxt;
	}
	last->nxt = *stack;
	*stack = last;
	tmp->nxt = NULL;
}

void	ft_rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
