/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:10 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/02 14:56:19 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Ultimo diventa primo
void	reverse_rotate(list *lst)
{
	list *n_0;
	list *n_n;
	list *n_nm1;

	n_0 = ff(lst);
	n_n = fl(lst);
	n_nm1 = n_n->bak;
	n_nm1->nxt = NULL;
	n_n->bak = NULL;
	n_0->bak = n_n;
	n_n->nxt = n_0;
	lst = n_n;
}

void	rra(bag *box)
{
	reverse_rotate(box->a);
	box->a = ff(box->a);
	write(1,"rra\n",4);
}

void	rrb(bag *box)
{
	reverse_rotate(box->b);
	box->b = ff(box->b);
	write(1,"rrb\n",4);
}

void	rrr(bag *box)
{
	reverse_rotate(box->a);
	reverse_rotate(box->b);
	write(1,"rrr\n",4);
}
