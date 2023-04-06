/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:44:55 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 22:51:58 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void conv(int ac, char **av, bag *box)
{
	int	i;
	list	*node;

	i = -1;
	while(++i <= ac)
	{
		node = (list *)ft_calloc(1, sizeof(list));
		if(!node)
		{
			ft_free(node);
			return(1);
		}
		node.arg = ft_atoi (*av[i + 1]);
		node->islis = 0;
		ft_lstadd_back (box->a, node);
	}
	box->argnum = ac - 1;
}
//protrei ampliare con ft_join e ft_split per unire e riseparare correttamante gli av anche se passati come str unica
