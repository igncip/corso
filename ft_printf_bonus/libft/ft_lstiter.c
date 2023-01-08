/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:45:54 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:45:55 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_cpy;

	lst_cpy = lst;
	while (lst_cpy)
	{
		(*f)(lst_cpy->content);
		lst_cpy = lst_cpy->next;
	}
}
