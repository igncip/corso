/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpyevo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:07:42 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/14 17:38:47 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpyevo(char *dst, const char *src, size_t size, int f1)
{
	size_t	index;
	size_t	len;
	char	*src_cpy;

	src_cpy = (char *)src;
	index = 0;
	if (size == 0)
		return (ft_strlen(src_cpy));
	while (index < size - 1 && src_cpy[index] != '\0')
	{
		dst[index] = src_cpy[index];
		index++;
	}
	dst[index] = '\0';
	len = ft_strlen(src);
	if (f1 != 0)
		src = ft_free(&src_cpy);
	return (len);
}
