/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:14 by ajordan-          #+#    #+#             */
/*   Updated: 2022/11/28 22:39:10 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_return(char *buff_str)
{
	int		index;
	char	*rtn_line;

	index = 0;
	if (!buff_str[index])
		return (NULL);
	while (buff_str[index] && buff_str[index] != '\n')
		index++;
	rtn_line = (char *)ft_calloc((index + 2), sizeof(char));
	if (!rtn_line)
		return (rtn_line = ft_free(rtn_line));
	index = 0;
	while (buff_str[index] && buff_str[index] != '\n')
	{
		rtn_line[index] = buff_str[index];
		index++;
	}
	if (buff_str[index] == '\n')
	{
		rtn_line[index] = buff_str[index];
		index++;
	}
	return (rtn_line);
}

char	*ft_new_static(char *old_str)
{
	int		index_1;
	int		index_2;
	char	*new_str;

	index_1 = 0;
	while (old_str[index_1] && old_str[index_1] != '\n')
		index_1++;
	if (!old_str[index_1])
		return (old_str = ft_free(old_str));
	new_str = (char *)ft_calloc((ft_strlen(old_str) - index_1 + 1),
			sizeof(char));
	if (!new_str)
		return (new_str = ft_free(new_str));
	index_1++;
	index_2 = 0;
	while (old_str[index_1])
		new_str[index_2++] = old_str[index_1++];
	old_str = ft_free(old_str);
	return (new_str);
}

char	*ft_get_buff(int fd, char *origin)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (buff = ft_free(buff));
	rd_bytes = 1;
	while (!ft_strchr(origin, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (buff = ft_free(buff));
		buff[rd_bytes] = '\0';
		origin = ft_strjoin(origin, buff);
	}
	buff = ft_free(buff);
	return (origin);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str = ft_get_buff(fd, static_str);
	if (!static_str)
		return (static_str = ft_free(static_str));
	line = ft_get_return(static_str);
	static_str = ft_new_static(static_str);
	return (line);
}
