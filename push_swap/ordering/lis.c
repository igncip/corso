/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:55:48 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 17:55:48 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct
{
	int		*a;
	int		*b;
	int		*c;
	int		ac;
	int		i;
	int		j;
	int		max;
	list	*lst;
}	liis;

//find the lis
void	lis2(liis k)
{
	k.i = 0;
	while (++k.i < k.ac)
	{
		k.j = -1;
		while (++k.j < k.i)
		{
			if (k.a[k.i] > k.a[k.j] && k.b[k.i] < k.b[k.j] + 1)
			{
				k.b[k.i] = k.b[k.j] + 1;
				k.c[k.i] = k.j;
			}
		}
	}
	k.i = 0;
	k.max = 0;
	while (++k.i < k.ac)
	{
		if (k.b[k.max] < k.b[k.i])
			k.max = k.i;
	}
}

//modifico la flag nei nodi della lista se e' un elemento della lis
void islis(liis k, bag *b)
{
	k.lst = ff(b->a);
	while (++k.i < k.ac)
	{
		if(k.j < k.b[k.i])
		{
			k.max = k.b[k.i];
			k.j = k.i;
		}
	}
	while (k.j)
	{
		farg(b->a, k.a[k.j])->islist = 1;
		k.j = k.c[k.j];
	}
}

void	lis(bag *b)
{
	liis k;

	k.ac = b.argnum;
	k.a = (int *) ft_calloc(k.ac, sizeof(int));
	k.b = (int *) ft_calloc(k.ac, sizeof(int));
	k.c = (int *) ft_calloc(k.ac, sizeof(int));
	k.i = 0;
	k.max = 0;
	k.lst = ff(b->a);
	while (k.lst)
		k.a[k.i] = k.lst->arg;
	lis2(k);
	islis(k, b);
	k.a = ft_free (k.a);
	k.b = ft_free (k.b);
	k.c = ft_free (k.c);
}

