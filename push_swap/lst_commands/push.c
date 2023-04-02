/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:14 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:20 by igncipri         ###   ########.fr       */
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

void	pa(bag box)
{
	push(box->b, box->a);
	write(1,"pa\n",3);
}

void	pb(bag box)
{
	push(box->a, box->b);
	write(1,"pb\n",3);
}
