/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:50:10 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:50:11 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check(char const *set, char const c)
{
	size_t	index;

	index = -1;
	while (set[++index] != '\0')
	{
		if (c == set[index])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			leng;
	unsigned int	index;
	char			*dest;

	leng = ft_strlen(s1);
	while (ft_check(set, s1[leng - 1]))
		leng--;
	index = 0;
	while (ft_check(set, s1[index]))
	{
		index++;
		leng--;
	}
	dest = ft_substr(s1, index, leng);
	if (!dest)
		return (NULL);
	return (dest);
}
