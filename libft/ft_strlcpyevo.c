/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpyevo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:42 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/15 19:17:23 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpyevo(char *dst, const char *src, size_t size, int f1)
{
	size_t	index;
	size_t	len;

	index = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (index < size - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	len = ft_strlen(src);
	if (f1 != 0)
		src = ft_free(src);
	return (len);
}
