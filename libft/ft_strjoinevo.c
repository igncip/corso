/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinevo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:49:49 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/15 19:17:12 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinevo(char const *s1, char const *s2, int f1 , int f2)
{
	int			index;
	char		*dst;
	char const	*s1_cpy;
	char const	*s2_cpy;

	s1_cpy = s1;
	s2_cpy = s2;
	dst = (char *) ft_calloc(((ft_strlen(s1_cpy) + ft_strlen(s2_cpy)) + 1),
		sizeof (char));
	if (!dst)
		return (ft_free(dst));
	index = 0;
	while (*s1_cpy)
		dst[index++] = *s1_cpy++;
	while (*s2_cpy)
		dst[index++] = *s2_cpy++;
	if (f1 != 0)
		s1_cpy = ft_free(s1_cpy);
	if (f2 != 0)
		s2_cpy = ft_free(s2_cpy);
	return (dst);
}
