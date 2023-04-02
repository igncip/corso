/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:17:46 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 19:29:33 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_init_words(char const *str, char c)
{
	size_t	dst;
	size_t	i;

	if (!str)
		return (0);
	dst = 0;
	i = 0;
	if (str[i] && str[i] != c)
		dst++;
	while (str[i] && str[i + 1])
	{
		if (str[i] == c && str[i + 1] != c)
			dst++;
		i++;
	}
	return (dst);
}

char	**ft_split(char const *str, char c)
{
	size_t	words;
	char	**dst;
	size_t	i;
	size_t	len;

	words = ft_init_words(str, c);
	dst = malloc(sizeof(char *) * (words + 1));
	if (!dst)
		return (NULL);
	dst[words] = NULL;
	i = 0;
	while (words)
	{
		len = 0;
		while (*str == c)
			s++;
		while (*str && *str != c)
		{
			len++;
			str++;
		}
		dst[i++] = ft_substr(str - len, 0, len);
		words--;
	}
	return (dst);
}
