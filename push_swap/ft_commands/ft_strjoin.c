/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:05:46 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 19:05:59 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	index_1;
	size_t	index_2;
	char	*dst;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s2)
		s2 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (s1 = ft_free(s1));
	dst = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	if (!dst)
		return (dst = ft_free(dst));
	index_1 = -1;
	index_2 = 0;
	if (s1)
		while (s1[++index_1] != '\0')
			dst[index_1] = s1[index_1];
	while (s2[index_2] != '\0')
		dst[index_1++] = s2[index_2++];
	dst[index_1] = '\0';
	s1 = ft_free(s1);
	return (dst);
}
