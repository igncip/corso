/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:22:42 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/06 18:07:23 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_return(char	*read_memory)
{
	int		index;
	char	*return_str;

	index = 1;
	while (read_memory[index] != '\n' && read_memory[index] != '\0')
		index++;
	return_str = (char *) ft_calloc (sizeof(char), index);
	if (!return_str)
	{
		free(return_str);
		return (NULL);
	}
	return_str[index + 1] = '\0';
	while (--index >= 0)
		return_str[index] = read_memory[index];
	return (return_str);
}

char	*ft_read_buff(char *read_memory, int fd)
{
	void		*read_buff;
	int			read_num;

	if (ft_strchr (read_memory, '\n'))
		return (read_memory);
	read_buff = (char *) ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!read_buff)
		return ('\0');
	read_num = 1;
	while (!ft_strchr (read_memory, '\n') && read_num > 0)
	{
		read_num = read(fd, read_buff, BUFFER_SIZE);
		if (read_num < 0)
		{
			free (read_buff);
			return ('\0');
		}
		else if (read_num > 0)
			read_memory = ft_strjoin(read_memory, (char *)read_buff);
	}
	free (read_buff);
	return (read_memory);
}

	/*inserire controllo per file binario nella funzion sotto*/

char	*get_next_line(int fd)
{
	static char	*read_memory;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_memory = ft_read_buff (read_memory, fd);
	return_str = ft_get_return (read_memory);
	read_memory = (ft_strchr (read_memory, '\n'));
	if (read_memory[0] == '\n')
		read_memory++;
	return (return_str);
}
