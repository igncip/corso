/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:50:28 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/08 21:50:31 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	dest_leng;
	size_t	start_cast;

	start_cast = (size_t)start;
	if (start_cast >= (size_t) ft_strlen(s))
		return (ft_strdup(""));
	if ((start_cast + len) >= (size_t) ft_strlen(s))
		dest_leng = ((size_t) ft_strlen(s)) - start_cast;
	else
		dest_leng = len;
	dest = (char *) malloc((dest_leng + 1) * sizeof (char));
	if ((!dest) || (!s))
		return (NULL);
	ft_strlcpy(dest, &s[start_cast], (dest_leng + 1));
	return (dest);
}
