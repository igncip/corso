/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:46:59 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:47:01 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*new_node;
	t_list	*current_node;

	current_node = lst;
	if (current_node == NULL)
		return (NULL);
	dest = NULL;
	while (current_node)
	{
		new_node = ft_lstnew((*f)(current_node->content));
		if (new_node == NULL)
			ft_lstclear(&new_node, (*del));
		else
			ft_lstadd_back(&dest, new_node);
		current_node = current_node->next;
	}
	return (dest);
}
