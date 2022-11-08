/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:07:52 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/30 15:17:59 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = ft_calloc((ft_strlen (s) + 1), sizeof (char));
	if (!dst)
		return (NULL);
	ft_strlcpy (dst, s, (ft_strlen (s) + 1));
	return (dst);
}
