/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:54:59 by igncipri          #+#    #+#             */
/*   Updated: 2023/01/08 16:40:37 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct
{
	//stable
	int				index;
	char			*str;
	//temporary
	char			format;
	int				form_buff;//form_buff+index = index of the first format after % at index
	int				p_leng;
	int				width;//Flags
	int				dot;
	int				phi;
	int				minus;
	int				plus;
	int				hashtag;
	int				space;
}	t_list;