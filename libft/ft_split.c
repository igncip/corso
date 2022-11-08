/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:49:28 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/08 22:55:57 by igncipri         ###   ########.fr       */
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
	flag = 0;
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

void	*ft_free(char **mtx)
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
		return (ft_free(return_mtx));
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
/*
static int	ft_word_number(char const *s_cpy, char c)
{
	size_t	word_number;
	size_t	index;

	index = 0;
	word_number = 0;
	while (s_cpy[index] != '\0')
	{
		while (s_cpy[index] == c)
			index++;
		if ((s_cpy[index] != c) && (s_cpy[index] != '\0'))
			word_number++;
		while ((s_cpy[index] != c) && (s_cpy[index] != '\0'))
			index++;
	}
	return (word_number);
}

static char	*ft_create_word(char const *s_cpy, char c)
{
	char	*word_string;
	int		index;

	index = 0;
	while ((s_cpy[index] != '\0') && (s_cpy[index] != c))
		index++;
	word_string = (char *) malloc(sizeof(char) * (index + 1));
	if (!word_string)
		return (NULL);
	ft_strlcpy(word_string, s_cpy, index + 1);
	return (word_string);
}

static void	*ft_free(char **mtx, int index)
{
	while (index > 0)
		free (mtx[index--]);
	free(mtx);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			w_index;
	int			w_number;
	char		**return_mtx;
	char const	*s_cpy;

	if (!s)
		return (NULL);
	s_cpy = s;
	w_number = ft_word_number(s_cpy, c);
	return_mtx = (char **) malloc(sizeof(char *) * (w_number + 1));
	if (!return_mtx)
		return (NULL);
	w_index = -1;
	while (++w_index < w_number)
	{
		while (s_cpy[0] == c)
			s_cpy++;
		return_mtx[w_index] = ft_create_word(s_cpy, c);
		if (!return_mtx[w_index])
			return (ft_free(return_mtx, w_index));
		s_cpy = s_cpy + ft_strlen((char *)return_mtx[w_index]);
	}
	return_mtx[w_index] = 0;
	return (return_mtx);
}*/