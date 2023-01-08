/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:49:28 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/10 20:14:44 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_length(char const *s, char c, size_t index)
{
	size_t	w_len;

	w_len = 0;
	while (s[index + w_len] != c && s[index + w_len] != '\0')
		w_len++;
	return (w_len);
}

size_t	ft_word_count(char const *s, char c)
{
	size_t	index;
	size_t	w_number;
	size_t	flag;

	index = 0;
	w_number = 1;
	flag = 1;
	while (s[index] != '\0')
	{
		if (flag == 0 && s[index] == c)
		{
			flag = 1;
			w_number++;
		}
		else if (s[index] != c)
			flag = 0;
		index++;
	}
	if (flag == 1)
		w_number--;
	return (w_number + 1);
}

void	*ft_free_mtx(char **mtx)
{
	free (mtx);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**return_mtx;
	size_t	index;
	size_t	w_index;
	size_t	w_size;

	index = 0;
	w_index = 0;
	w_size = 0;
	return_mtx = (char **) ft_calloc(ft_word_count(s, c), sizeof(char *));
	if (!return_mtx)
		return (ft_free_mtx(return_mtx));
	while (s[index] != '\0')
	{
		if (s[index] == c)
			index++;
		else
		{
			w_size = ft_word_length(s, c, index);
			return_mtx[w_index++] = ft_substr(s, index, w_size);
			index += w_size;
		}
	}
	return_mtx[w_index] = NULL;
	return (return_mtx);
}
