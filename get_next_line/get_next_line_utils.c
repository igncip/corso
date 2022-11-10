/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:14:52 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/10 22:54:28 by igncipri         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (!s)
		return (NULL);
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
	if (s1)
	{
		while (*s1)
			dst[index++] = *s1++;
	}
	while (*s2)
		dst[index++] = *s2++;
	dst[index] = '\0';
	return (dst);
}
