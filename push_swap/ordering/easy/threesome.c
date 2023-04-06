/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesome.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:38:59 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 22:41:57 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//123; 132; 213; 231; 312; 321
void	order_a(bag *b)
{
	if (b->a->arg < b->a->nxt->arg && b->a->nxt->arg < b->a->nxt->nxt->arg)
		return;
	else if (b->a->arg < b->a->nxt->nxt->arg \
		&& b->a->nxt->nxt->arg < b->a->nxt->arg)
	{
		sa(b);
		rra(b);
	}
	else if (b->a->nxt->arg < b->a->arg \
		&& b->a->arg < b->a->nxt->nxt->arg)
		sa(b);
	else if (b->a->nxt->nxt->arg < b->a->arg \
		&& b->a->arg < b->a->nxt->arg)
		ra(b);
	else if (b->a->nxt->arg < b->a->nxt->nxt->arg \
		&& b->a->nxt->nxt->arg < b->a->arg)
		rra(b);
	else if (b->a->nxt->nxt->arg < b->a->nxt->arg && b->a->nxt->arg < b->a->arg)
	{
		sa(b);
		ra(b);
	}
	return;
}

void	threesome(bag *b)
{
	order_a(b);
	order_b(b);
	return;
}
