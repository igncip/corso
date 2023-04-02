/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:05:07 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 19:32:50 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	min_ctrl;
	int	val;

	i = 0;
	min_ctrl = 1;
	val = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		min_ctrl *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return ('\0');
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		val = val * 10 + (nptr[i] - '0');
		i++;
	}
	return (val * min_ctrl);
}