/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:15:32 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 18:42:08 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstadd_back(list **lst, list *new)
{
	list	*node;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			node = fl(*lst);
			node->nxt = new;
			new->bak = node;
		}
	}
}
