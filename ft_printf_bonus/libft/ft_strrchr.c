/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:24:42 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/30 14:11:39 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	flag;

	index = 0;
	flag = -1;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			flag = index;
		index++;
	}
	if (((char)c) == '\0')
		return (&((char *)s)[index]);
	else if (!ft_isascii(c))
		return ((char *)s);
	else if (flag == -1)
		return (NULL);
	else
		return (&((char *)s)[flag]);
}
