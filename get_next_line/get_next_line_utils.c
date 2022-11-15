/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:14:52 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/15 20:38:58 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((char *)s)[index] = '\0';
		index++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (NULL);
	ptr = (void *) malloc(nmemb * size);
	if ((!ptr) || (nmemb <= 0) || (size <= 0))
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	if (!s)
		return (0);
	while (s[lenght] != '\0')
		lenght++;
	return (lenght);
}

char	*ft_free(char const *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*ft_strjoinevo(char *s1, char *s2, int f1 , int f2)
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
