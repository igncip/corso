/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eordering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:55:40 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 22:55:40 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find second lowest
list	*fslo(list *lst)
{
	list	*cpy;
	list	*n;
	list	*n2;

	n = flo(lst);
	if (n == lst)
		n2 = lst->nxt;
	else
		n2 = lst;
	cpy = lst;
	while (cpy)
	{
		if (n2->arg > cpy->arg && n->arg != cpy->arg)
			n2 = cpy;
		cpy = cpy->nxt;
	}
	return (n2);
}

//count moves
int	ct_mv(list *a, list *n)
{
	int		i;
	list	*cpy;

	i = 0;
	cpy = a;
	while (cpy != a)
		i++;
	if (i == 4)
		i = -2;
	else if (i == 5)
		i = -1;
}

void	push_this(list *ntp, bag *b)
{
	if (b->a == ntp)
		pb(b);
	else if (b->a->nxt == ntp)
	{
		ra(b);
		pb(b);
	}
	else
	{
		rra(b);
		pb(b);
	}
	return;
}

//devo selezionare in base al numero minimo di passaggi quale dei tre effettuare
void	which_push(bag *b)
{
	if (ct_mv(b->a, flo(b->a)) <= ct_mv(b->a, fslo(b->a)) && \
		ct_mv(b->a, flo(b->a)) <= ct_mv(b->a, fhi(b->a)))
		push_this(ct_mv(b->a, flo(b->a)), b);
	else if (ct_mv(b->a, fslo(b->a)) <= ct_mv(b->a, flo(b->a)) && \
		ct_mv(b->a, fslo(b->a)) <= ct_mv(b->a, fhi(b->a)))
		push_this(ct_mv(b->a, fslo(b->a)), b);
	else if (ct_mv(b->a, fhi(b->a)) <= ct_mv(b->a, fslo(b->a)) && \
		ct_mv(b->a, fhi(b->a)) <= ct_mv(b->a, flo(b->a)))
		push_this(ct_mv(b->a, fhi(b->a)), b);
	return;
}
