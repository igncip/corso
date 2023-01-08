/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:47:25 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:47:27 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*lst_cpy;

	lst_cpy = lst;
	counter = 0;
	while (lst_cpy)
	{
		lst_cpy = lst_cpy->next;
		counter++;
	}
	return (counter);
}
