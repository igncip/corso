/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:56:37 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:16 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	bag	box;

	if(argck (argc, **argv))
	{
		write(1, "Error", 5);
		return (0);
	}
	box = (* bag) ft_calloc (1, sizeof(bag));
	conv (argc, **argv, box);
	return(0);
}

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

char **ft_splitter(char *str, char char)
{

}
ft_new_argc()
{

}