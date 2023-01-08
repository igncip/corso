/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_elaboration.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:54:21 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/08 19:58:44 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(uintptr_t ptr)//pointer
{
	char	*dest;
	int		print_length;

	dest = ft_ptrtoa(ptr);
	print_length = ft_printstr(dest);
	ft_free(dest);
	return (print_length);
}

int	ft_printnbr(int number)//integer
{
	char	*dest;
	int		print_length;

	dest = ft_itoa(number);
	print_length = ft_printstr(dest);
	ft_free(dest);
	return (print_length);
}

int	ft_print_unsigned(unsigned int unsign_nbr)//unsigned
{
	char	*dest;
	int		print_length;

	dest = ft_utoa(unsign_nbr);
	print_length = ft_printstr(dest);
	ft_free(dest);
	return (print_length);
}

int	ft_print_hex(unsigned int hex_nbr, format)//hexadecimal
{
	char	*dest;
	int		print_length;

	if(format == "x")
		dest = ft_itoa_hex(hex_nbr);
	else
		dest = ft_itoa_HEX(hex_nbr);
	print_length = ft_printstr(dest);
	ft_free(dest);
	return (print_length);
}

int	ft_printpercent()//percent
{
	write(1, '%', 1);
	return (1);
}