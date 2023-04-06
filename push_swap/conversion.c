/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:17:14 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 19:04:29 by igncipri         ###   ########.fr       */
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
}
/*
char *ft_joiner(int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	while (++i <= ac)
	{
		str = ft_join (str, " ");
		str = ft_join (str, av[i]);
	}
	return (str);
}

char **ft_splitter(char *str, char c)
{

}

ft_new_argc()
{

}
*/
