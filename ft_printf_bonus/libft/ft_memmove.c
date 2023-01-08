/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:58:48 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/08 20:58:49 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (ft_strlen((const char *)src) >= ft_strlen((const char *)dest))
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
	{
		index = 0;
		while (index < n)
		{
			((char *)dest)[index] = ((char *)src)[index];
			index++;
		}
	}
	return (dest);
}
