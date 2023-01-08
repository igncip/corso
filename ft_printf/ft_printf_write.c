/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:58:34 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/08 19:58:55 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)//char
{
	if(bag->width >= 1)
		ft_width(bag->width, 1);
	write(1, &c, 1);
	if(bag->minus >= 1)
		ft_width(bag->minus, 1);
	return (1);
}

int	ft_printstr(str)//string
{
	int		index;

	index = 0
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[index] != '\n')
	{
		write(1, &str[index], 1);
		index++
	}
	return (index);
}