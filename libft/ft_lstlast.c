/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:46:50 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:46:51 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_cpy;

	lst_cpy = lst;
	if (lst_cpy == NULL)
		return (lst_cpy);
	while (lst_cpy->next != NULL)
		lst_cpy = lst_cpy->next;
	return (lst_cpy);
}
