/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:55:17 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/03 23:31:42 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


/*               **********---TO DO---**********
-aggiungere lo zainetto nella dichiarazione di print char e print str
-creare lo zainetto in printf.h
-aggiungere la funzione di riempimento dello zainetto
-fare il free dello zainetto dopo la stampa
*/

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
			format_index = ft_bag_packer(bag, str[i + 1])
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

//UTILS
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
	if(bag->width >= 1)
	{
		if(!str)
			ft_width(bag->width, 6);
		else
			ft_width(bag->width, ft_strlen(str));
	}
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
	if(bag->minus >= 1)
		ft_width(bag->minus, index);
	return (index);
}

int	ft_print_ptr(uintptr_t ptr)//pointer
{
	char	*dest;
	int		print_length;

	dest = ft_ptrt
	oa(ptr);
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

//flags
ft_width(int n_char, int to_print)
{
	int	index;

	index = 0;
	while ((index + to_print) < n_char)
	{
		write(1, ' ', 1);//controllare se vuole "spazi" o "0"
		index++;
	}
}

ft_minus(int n_char, int printed)
{
	int	index;

	index = 0;
	while ((index + printed) < n_char)
	{
		write(1, ' ', 1);//controllare se vuole "spazi" o "0"
		index++;
	}
}
