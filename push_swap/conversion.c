/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:17:14 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 21:37:32 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void conv(int ac, char **av, bag box)
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
		ft_lstadd_back (box->a, node);
	}
}
