/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:24:52 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/08 21:37:58 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == ((char)c))
			return (&((char *)s)[index]);
		index++;
	}
	if (((char)c) == '\0')
		return (&((char *)s)[index]);
	return (NULL);
}
