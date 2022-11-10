/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:49:49 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/10 20:24:03 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			index;
	char		*dst;
	char const	*s1_cpy;
	char const	*s2_cpy;

	s1_cpy = s1;
	s2_cpy = s2;
	dst = (char *) malloc(((ft_strlen(s1_cpy) + ft_strlen(s2_cpy)) + 1)
			* sizeof (char));
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
