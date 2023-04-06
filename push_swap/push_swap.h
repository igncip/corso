/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:57:08 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/06 19:03:40 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct node
{
	int			arg;
	int			islis;
	struct node	*nxt;
	struct node	*bak;
}	list;

typedef struct
{
	list	*a;
	list	*b;
	list	higest;
	list	lowest;
	list	midnbr;
	int		argnum;
}	bag;

to_do:
ft_free con il void
free_node creare funzione

push_swap
	prepare
		join
		split
		arg_count
	check
		valid_nbr
			is_int
		duplicate_nbr

		free
		error
	conversion
		
	elaboration
	return

#endif
