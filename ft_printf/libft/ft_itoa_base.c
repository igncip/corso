/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:53:33 by igncipri          #+#    #+#             */
/*   Updated: 2022/12/13 22:53:37 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_nbrleng(int n, char *base)
{
	size_t			index;
	unsigned int	n_cpy;
	size_t	base_leng;

	base_leng = ft_strlen(base);
	index = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n_cpy = n * -1;
		index++;
	}
	else
		n_cpy = n;
	while (n_cpy > 0)
	{
		n_cpy /= base_leng;
		index++;
	}
	return (index);
}

void	ft_conversion(char *dest, int n, char *base)
{
	size_t			dest_leng;
	unsigned int	n_cpy;
	size_t	base_leng;

	base_leng = ft_strlen(base);
	dest_leng = ft_nbrleng(n, base);
	dest[dest_leng--] = '\0';
	if (!n)
		dest[dest_leng] = '0';
	if (n < 0)
	{
		dest[0] = '-';
		n_cpy = n * -1;
	}
	else
		n_cpy = n;
	while (n_cpy)
	{
		dest[dest_leng--] = base[n_cpy % base_leng];
		n_cpy /= base_leng;
	}
}

char	*ft_itoa_base(int n, char *base)
{
	char	*dest;
	dest = (char *) ft_calloc((ft_nbrleng(n, base) + 1), (sizeof(char)));
	if (!dest)
		return (NULL);
	ft_conversion(dest, n, base);
	return (dest);
}