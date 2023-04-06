/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orgy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:50:47 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/31 21:53:36 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	orgy(bag *b)
{
	which_push(b);
	foursome(b);
	pa(b);
	if (b->a->arg > fl(b->a)->arg)
		rra(b);
	else if (b->a->arg > b->a->nxt->arg)
		sa(b);
	return;
}
