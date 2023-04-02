/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:18 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:19 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Primo diventa ultimo
void	rotate(list *list)
{
	list *node_0;
	list *node_1;
	list *node_n;

	node_0 = ff(list);
	node_1 = node_0->nxt;
	node_n = fl(list);
	node_1->bak = NULL;
	node_n->nxt = node_0;
	node_0->bak = node_n;
	node_0->nxt = NULL;
	list = node_1;
}

void	ra(bag bag)
{
	rotate(bag->a);
	write(1,"ra\n",3);
}

void	rb(bag bag)
{
	rotate(bag->b);
	write(1,"rb\n",3);
}

void	rr(bag bag)
{
	rotate(bag->a);
	rotate(bag->b);
	write(1,"rr\n",3);
}
