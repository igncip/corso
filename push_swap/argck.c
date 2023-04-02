/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argck.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:46:08 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 20:31:08 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//duplicate number
int	dup_num(int ac, char **av, int i)
{
	int	n;
	int	j;

	n = -1;
	while (i + ++n <= ac)
	{
		j = 0;
		while (av[i + n][j] == av[i][j]
			&& ((av[i + n][j] != '\0') != (av[i][j] != '\0')))
		{
			if (av[i + n][j] == '\0' && av[i][j] == '\0')
				return (1);
			j++;
		}
	}
	return (0);
}

//valid number
int	val_num(char *str)
{
	int	i;

	i = 0;
	if (!(str[0] == '+' || str[0] == '-' || (str[0] > 47 && str[0] < 58)))
		return (1);		
	while (str[++i] != '\0')
	{
		if (!(str[i] > 47 && str[i] < 58))
			return (1);
	}
	if(ft_atol(str) > INT_MAX && ft_atol(str) < INT_MIN)
		return (1);
	return (0);
}

//arguments check
int	argck(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i <= ac)
	{
		if (val_num(*av[i]))
			return (1);
		else if (dup_num(ac, **av, i))
			return (1);
	}
	return (0);
}
