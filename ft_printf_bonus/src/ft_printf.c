/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:55:17 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/08 16:59:51 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"


/*               **********---TO DO---**********
-aggiungere lo zainetto nelle dichiarazioni
-creare lo zainetto in printf.h
-aggiungere la funzione di riempimento dello zainetto
-fare il free dello zainetto dopo la stampa
*/

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length
	if (bag->format == 'c')//char
		print_length += ft_printchar(va_arg(args, int), bag)
	else if (bag->format == 's')//string
		print_length += ft_printstr(va_arg(args, char *), bag)
	else if (bag->format == 'p')//pointer
		print_length += ft_print_ptr(va_arg(args, uintptr_t), bag)
	else if (bag->format == 'd' || bag->format == 'i')//integer
		print_length += ft_printnbr(va_arg(args, int), bag)
	else if (bag->format == 'u')//unsigned number
		print_length += ft_print_unsigned(va_arg(args, unsigned int), bag)
	else if (bag->format == 'x' || bag->format == 'X')//hexadecimal
		print_length += ft_print_hex(va_arg(args, unsigned int), bag);
	else if (bag->format == '%')//percentual
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	//create-bag
	va_start(args, str);
	while (str[bag->index])
	{
		if (str[bag->index] == '%')
		{
			ft_bag_packer(bag);//initialize bag with the flags and momentary p_leng
			print_length += ft_formats(bag, args);
			ft_empty_bag(bag);//clean the flags and update the index to form_buff
		}
		else
			print_length += ft_print(str[i]);
		bag->index++;
	}
	va_end(args);
	//free bag
	return (print_length);
}

//UTILS
int	ft_print(char	c)//char
{
	write(1, &c, 1);
	return (1);
}

int	ft_printchar(struct bag)//char
{
	int	print_length;
	ft_berfore_print(bag);
	write(1, &c, 1);
	bag->p_leng += 1;
	ft_after_print(bag);
	return (bag->p_leng);
}

int	ft_printstr(struct bag)//string
{
	int		index;

	index = 0
	if (bag->print_str == NULL)
	{
		bag->print_str = "(null)";
	}
	ft_berfore_print(bag);
	while (str[index] != '\n')
	{
		write(1, &bag->print_str[index], 1);
		index++
	}
	bag->p_leng += index;
	ft_after_print(bag);
	return (bag->p_leng);
}

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

	if(bag->format == "x")
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
ft_width(int n_char, int to_print)// W 
{
	int	index;

	index = 0;
	while ((index + to_print) < n_char)
	{
		write(1, ' ', 1);//controllare se vuole "spazi" o "0"
		index++;
	}
}

ft_minus(int n_char, int printed)// minus
{
	int	index;

	index = 0;
	while ((index + printed) < n_char)
	{
		write(1, ' ', 1);//controllare se vuole "spazi" o "0"
		index++;
	}
}

//flag print elaboration
void	ft_berfore_print(struct bag)
{
	peni;
}

void	ft_after_print(struct bag)
{
	peni;
}

//BAG ELABORATION
void	ft_bag_packer(struct bag)
{
	peni;
}

void	ft_empty_bag(struct bag)
{
	peni;
}
