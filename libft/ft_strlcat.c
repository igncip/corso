/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:11:41 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/03 19:11:43 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	index;

	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (size + ft_strlen(src));
	index = 0;
	while (src[index] != '\0' && index < (size - dstlen - 1))
	{
		dst[index + dstlen] = src[index];
		index++;
	}
	dst[index + dstlen] = '\0';
	return (dstlen + ft_strlen(src));
}
