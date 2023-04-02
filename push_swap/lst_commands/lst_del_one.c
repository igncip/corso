/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:39:16 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 18:42:07 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_del_one(list *node, list *list)
{
	if (node->nxt != NULL)
		node->nxt->bak = node->bak;
	if (node->bak != NULL)
		node->bak->nxt = node->nxt;
	else
		list = ff(node->nxt);
	free_node((void *)node);
}
