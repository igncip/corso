/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foursome.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:49:41 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/31 22:13:14 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_one(bag *box)
{
	if (box->a == flo(box->a))
		pb(box);
	else if (box->a->nxt == flo(box->a))
	{
		ra(box);
		pb(box);
	}
	else if (fl(box->a) == flo(box->a))
	{
		rra(box);
		pb(box);
	}
	else if (box->a->nxt->nxt == flo(box->a) && box->a == fhi(box->a))
		pb(box);
	else
	{
		ra(box);
		ra(box);
		pb(box);
	}
}

void	foursome(bag *b)
{
	push_one(b);
	threesome(b->a);
	pa(b);
	if (b->a->arg > fl(b->a)->arg)
		rra(b);
	else if (b->a->arg > b->a->nxt->arg)
		sa(b);
}
