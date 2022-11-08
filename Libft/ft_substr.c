/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:50:28 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/06 19:48:14 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (start >= (unsigned int) ft_strlen(s))
		len = 0;
	dest = (char *) malloc((len + 1) * sizeof (char));
	if ((!dest) || (!s))
		return (NULL);
	ft_strlcpy(dest, &s[start], (len + 1));
	return (dest);
}
