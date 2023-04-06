/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:56:37 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 21:43:56 by igncipri         ###   ########.fr       */
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
