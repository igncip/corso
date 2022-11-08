/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:55:10 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/08 18:55:12 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*s_conv;

	s_conv = ((char *)s);
	index = 0;
	while (index < n)
	{
		if (s_conv[index] == ((char)c))
			return (&s_conv[index]);
		index++;
	}
	return (NULL);
}
