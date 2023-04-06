/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:14:25 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/02 14:56:53 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Scambia il primo con il secondo nodo
void	swap(list *lst)
{
	list *n_0;
	list *n_1;
	list *n_2;


	n_0 = ff(lst);
	n_1 = n_0->nxt;
	n_2 = n_0->nxt->nxt;
	n_1->bak = NULL;
	n_1->nxt = n_0;
	n_0->bak = n_1;
	n_0->nxt = n_2;
	if (n_2)
		n_2->bak = n_0;
	lst = n_1;
}

void	sa(bag *box)
{
	swap(box->a);
	box->a = ff(box->a);
	write(1,"sa\n",3);
}

void	sb(bag *box)
{
	swap(box->b);
	box->b = ff(box->b);
	write(1,"sb\n",3);
}

void	ss(bag *box)
{
	swap(box->a);
	swap(box->b);
	write(1,"ss\n",3);
}
