/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:49:49 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:49:51 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		index;
	int		index_2;
	char	*dst;

	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((len + 1) * sizeof (char));
	if (!dst)
		return(NULL);
	index = -1;
	while (s1[++index] != '\0')
		dst[index] = s1[index];
	index_2 = -1;
	while (s2[++index_2] != '\0')
		dst[++index] = s2[index_2];
	dst[++index] = '\0';
	return(dst);
}*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		index;
	char	*dst;

	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc((len + 1) * sizeof (char));
	if (!dst)
		return (NULL);
	index = 0;
	while (*s1)
		dst[index++] = *s1++;
	while (*s2)
		dst[index++] = *s2++;
	dst[index] = '\0';
	return (dst);
}
