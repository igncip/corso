/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:10 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:20 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Ultimo diventa primo
void	reverse_rotate(list *lista)
{
	list *node_0;
	list *node_n;
	list *node_nm1;

	node_0 = ff(lista);
	node_n = fl(lista);
	node_nm1 = node_n->bak;
	node_nm1->nxt = NULL;
	node_n->bak = NULL;
	node_0->bak = node_n;
	node_n->nxt = node_0;
	lista = node_n;
}

void	rra(bag box)
{
	reverse_rotate(box->a);
	write(1,"rra\n",4);
}

void	rrb(bag box)
{
	reverse_rotate(box->b);
	write(1,"rrb\n",4);
}

void	rrr(bag box)
{
	reverse_rotate(box->a);
	reverse_rotate(box->b);
	write(1,"rrr\n",4);
}
