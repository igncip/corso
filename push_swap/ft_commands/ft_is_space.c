/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <igncipri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:28:15 by igncipri          #+#    #+#             */
/*   Updated: 2023/03/21 19:32:42 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ft_is_space(char c)
{
    if(c == ' ' || c == '\t' || c == '\n'
        || c == '\r' || c == '\v'|| c == '\f')
        return (1);
    return (0);
}