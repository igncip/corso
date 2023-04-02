/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:14:25 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 21:56:51 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Scambia il primo con il secondo nodo
void	swap(list *lst)
{
	list *node_0;
	list *node_1;
	list *node_2;


	node_0 = ff(lst);
	node_1 = node_0->nxt;
	node_2 = node_0->nxt->nxt;
	node_1->bak = NULL;
	node_1->nxt = node_0;
	node_0->bak = node_1;
	node_0->nxt = node_2;
	if (node_2)
		node_2->bak = node_0;
	lst = node_1;
}

void	sa(bag *box)
{
	swap(box->a);
	write(1,"sa\n",3);
}

void	sb(bag *box)
{
	swap(box->b);
	write(1,"sb\n",3);
}

void	ss(bag *box)
{
	swap(box->a);
	swap(box->b);
	write(1,"ss\n",3);
}
