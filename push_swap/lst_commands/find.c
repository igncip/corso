/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:57:52 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:23 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//find last
list *fl(list *lst)
{
	list *lst_cpy;

	lst_cpy = lst;
	while (lst_cpy->nxt != NULL)
		lst_cpy = lst_cpy->nxt;
	return (lst_cpy);
}

//find first
list *ff(list *lst)
{
	list *lst_cpy;

	lst_cpy = lst;
	while (lst_cpy->bak != NULL)
		lst_cpy = lst_cpy->bak;
	return (lst_cpy);
}

//find size
int fs(list *lst, int arg)
{
	list	*lst_cpy;
	int		i;

	i = 1;
	lst_cpy = ff(lst);
	if (!lst)
		return (0);
	while (lst_cpy->nxt != NULL)
	{
		lst_cpy = lst_cpy->nxt;
		i++;
	}
	return (i);
}

//find highest
list *fhi(list *lst, int arg)
{
	list *lst_cpy;
	list *n;

	lst_cpy = ff(lst)->nxt;
	n = ff(lst);
	while (lst_cpy)
	{
		if (lst_cpy->arg > n->arg)
			n = lst_cpy;
		lst_cpy = lst_cpy->nxt;
	}
	return(n);
}

//find lowest
list *flo(list *lst)
{
	list *lst_cpy;
	list *n;

	lst_cpy = ff(lst)->nxt;
	n = ff(lst);
	while (lst_cpy)
	{
		if (lst_cpy->arg < n->arg)
			n = lst_cpy;
		lst_cpy = lst_cpy->nxt;
	}
	return(n);
}
