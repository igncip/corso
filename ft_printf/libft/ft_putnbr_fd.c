/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:48:17 by igncipri          #+#    #+#             */
/*   Updated: 2022/10/14 20:48:18 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	index;
	char	print_str[11];
	int		n_cpy;

	print_str[10] = '\0';
	n_cpy = n;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n_cpy *= -1;
		}
		index = 9;
		while (n_cpy)
		{
			print_str[index--] = n_cpy % 10 + '0';
			n_cpy /= 10;
		}
		ft_putstr_fd(&print_str[index + 1], fd);
	}
}
