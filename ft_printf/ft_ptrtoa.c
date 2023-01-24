/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:53:33 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/24 21:28:20 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Non elabora "prt == 0" va gestito a monte della funzione

size_t	ft_ptrleng(uintptr_t n, char *base)
{
	size_t		index;
	uintptr_t	n_cpy;
	size_t		base_leng;

	base_leng = ft_strlen(base);
	index = 2;
	n_cpy = n;
	while (n_cpy > 0)
	{
		n_cpy /= base_leng;
		index++;
	}
	return (index);
}

void	ft_conve(char *dest, uintptr_t n, char *base)
{
	size_t		dest_leng;
	uintptr_t	n_cpy;
	size_t		base_leng;

	base_leng = ft_strlen(base);
	dest_leng = ft_ptrleng(n, base) - 1;
	dest[0] = '0';
	dest[1] = 'x';
	n_cpy = n;
	while (n_cpy)
	{
		dest[dest_leng--] = base[n_cpy % base_leng];
		n_cpy /= base_leng;
	}
}

char	*ft_ptrtoa(uintptr_t ptr)
{
	char	*dest;
	char	*base;

	base = "0123456789abcdef";
	dest = (char *) ft_calloc((ft_ptrleng(ptr, base) + 1), (sizeof(char)));
	if (!dest)
		return (NULL);
	ft_conve(dest, ptr, base);
	return (dest);
}
