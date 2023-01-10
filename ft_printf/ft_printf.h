/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:54:59 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/10 22:48:34 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_formats(va_list args, const char format);
int	ft_printf(const char *str, ...);
int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_print_ptr(uintptr_t ptr);
int	ft_printnbr(int number);
int	ft_print_unsigned(unsigned int unsign_nbr);
int	ft_print_hex(unsigned int hex_nbr, const char format);
int	ft_printpercent(const char format);

#endif