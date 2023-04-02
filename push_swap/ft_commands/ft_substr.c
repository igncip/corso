/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:17:25 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 19:29:31 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_min(size_t first, size_t second)
{
	if (first < second)
		return (first);
	return (second);
}

static size_t	ft_init_buffer(const char *str, unsigned int start, size_t len)
{
	size_t	buffer;

	buffer = ft_strlen(str) + 1;
	if (start >= buffer)
		return (1);
	if (len + 1 == 0)
		return (buffer - start);
	return (ft_min(len + 1, buffer - start));
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*output;
	size_t	buffer;

	if (!str)
		return (NULL);
	buffer = ft_init_buffer(str, start, len);
	output = ft_calloc(buffer, 1);
	if (!output)
		return (NULL);
	if (buffer != 1)
		ft_strlcpy(output, str + start, buffer);
	return (output);
}
