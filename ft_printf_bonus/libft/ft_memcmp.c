/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:55:29 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/30 14:46:02 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_conv;
	unsigned char	*s2_conv;

	s1_conv = ((unsigned char *)s1);
	s2_conv = ((unsigned char *)s2);
	index = 0;
	while (index < n)
	{
		if (s1_conv[index] != s2_conv[index])
			return (s1_conv[index] - s2_conv[index]);
		index++;
	}
	return (0);
}
