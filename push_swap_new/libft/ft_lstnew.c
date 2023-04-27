/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:22:37 by igncipri          #+#    #+#             */
/*   Updated: 2023/04/16 16:51:44 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int arg)
{
	t_list	*new;

	new = (t_list *) ft_calloc (1, sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->arg = arg;
	new->nxt = NULL;
	new->bak = NULL;
	return (new);
}
