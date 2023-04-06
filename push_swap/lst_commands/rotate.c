/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:18 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/02 14:56:39 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Primo diventa ultimo
void	rotate(list *lst)
{
	list *n_0;
	list *n_1;
	list *n_n;

	n_0 = ff(lst);
	n_1 = n_0->nxt;
	n_n = fl(lst);
	n_1->bak = NULL;
	n_n->nxt = n_0;
	n_0->bak = n_n;
	n_0->nxt = NULL;
	lst = n_1;
}

void	ra(bag *box)
{
	rotate(box->a);
	box->a = ff(box->a);
	write(1,"ra\n",3);
}

void	rb(bag *box)
{
	rotate(box->b);
	box->b = ff(box->b);
	write(1,"rb\n",3);
}

void	rr(bag *box)
{
	rotate(box->a);
	rotate(box->b);
	write(1,"rr\n",3);
}
