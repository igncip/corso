/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:25:20 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/08 16:25:21 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	lil_index;
	char	*big_conv;

	index = 0;
	big_conv = (char *)big;
	if (ft_strlen(little) == 0 || big == little)
		return (big_conv);
	if (len == 0)
		return (NULL);
	while (big_conv[index] != '\0' && index < len)
	{
		lil_index = 0;
		while (big_conv[index + lil_index] != '\0' && little[lil_index] != '\0'
			&& big_conv[index + lil_index] == little[lil_index]
			&& index + lil_index < len)
			lil_index++;
		if (lil_index == ft_strlen(little))
			return (big_conv + index);
		index++;
	}
	return (NULL);
}
