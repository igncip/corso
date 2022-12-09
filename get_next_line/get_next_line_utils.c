/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:04:40 by igncipri          #+#    #+#             */
/*   Updated: 2022/12/09 15:21:52 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((char *)s)[index] = ((char)c);
		index++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb >= __SIZE_MAX__ || size >= __SIZE_MAX__)
		return (NULL);
	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = (void *) malloc(nmemb * size);
	if ((!ptr) || (nmemb <= 0) || (size <= 0))
		return (NULL);
	ft_memset(ptr, 0, (nmemb * size));
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

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

char	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}
