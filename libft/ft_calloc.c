/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:36:18 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/21 19:19:59 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (NULL);
	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = (void *) malloc(nmemb * size);
	if ((!ptr) || (nmemb <= 0) || (size <= 0))
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
