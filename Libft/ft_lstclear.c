/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:45:17 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:45:19 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_cpy;

	while (*lst)
	{
		lst_cpy = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = lst_cpy;
	}
}
