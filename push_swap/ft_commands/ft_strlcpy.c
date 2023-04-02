/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:17:39 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 19:29:33 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size != 0)
	{
		index = -1;
		while (++index < size - 1 && src[index])
			dst[index] = src[index];
		dst[index] = 0;
	}
	return (ft_strlen(src));
}
