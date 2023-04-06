/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:14 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/02 15:00:40 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Il primo nodo di list_1 diventa il primo nodo di list_2
void	push(list *list_1, list *list_2)
{
	list *n0_l1;
	list *n1_l1;
	list *n0_l2;

	n0_l1 = ff(list_1);
	n1_l1 = n0_l1->nxt;
	n0_l2 = ff(list_2);
	n0_l1->nxt = n0_l2;
	n0_l2->bak = n0_l1;
	n1_l1->bak = NULL;
	list_1 = n1_l1;
	list_2 = n0_l1;
}

//push first b in a
void	pa(bag *box)
{
	box->b = box->b->nxt;
	push(box->b, box->a);
	box->a = ff(box->a);
	write(1,"pa\n",3);
}

//push first a in b
void	pb(bag *box)
{
	box->a = box->a->nxt;
	push(box->a, box->b);
	box->b = ff(box->b);
	write(1,"pb\n",3);
}
