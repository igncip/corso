/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:55:17 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/08 19:59:10 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')//char
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')//string
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')//pointer
		print_length += ft_print_ptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')//integer
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')//unsigned number
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')//hexadecimal
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')//percentual
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	int		format_index;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[format_index]);
			i = format_index + 1;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
