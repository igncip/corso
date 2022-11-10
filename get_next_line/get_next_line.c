/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:11 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/10 23:15:15 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_return(char	**read_memory)
{
	int		index;
	char	*return_str;

	index = 1;
	if (!read_memory)
		return (NULL);
	while ((*read_memory)[index - 1] != '\n'
		&& (*read_memory)[index - 1] != '\0')
		index++;
	return_str = (char *) ft_calloc (sizeof(char), index + 1);
	if (!return_str)
	{
		free(return_str);
		free(*read_memory);
		return (NULL);
	}
	while (--index >= 0)
		return_str[index] = (*read_memory)[index];
	return (return_str);
}

char	*ft_read_buff(char **read_memory, int fd)
{
	char		*read_buff;
	int			read_num;

	if (ft_strchr (*read_memory, '\n'))
		return (*read_memory);
	read_buff = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return ('\0');
	read_num = 1;
	while (!ft_strchr (*read_memory, '\n') && read_num > 0)
	{
		read_num = read(fd, read_buff, BUFFER_SIZE);
		if (read_num < 0)
		{
			free (read_buff);
			free(*read_memory);
			return ('\0');
		}
		else if (read_num > 0)
			*read_memory = ft_strjoin(*read_memory, read_buff);
	}
	free (read_buff);
	return (*read_memory);
}

	/*inserire controllo per file binario nella funzione sotto*/

char	*get_next_line(int fd)
{
	static char	*read_memory;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_memory = ft_read_buff (&read_memory, fd);
	return_str = ft_get_return (&read_memory);
	read_memory = (ft_strchr (read_memory, '\n'));
	if (read_memory && read_memory[0] == '\n')
		read_memory++;
	return (return_str);
}

/*TEST SECTION*/
#include <unistd.h>

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	// int		fd2;
	// int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
	// fd2 = open("tests/test2.txt", O_RDONLY);
	// fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 30)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line [%02d]: %s", i, line);
		// free(line);
		i++;
	}
	close(fd1);
	// close(fd2);
	// close(fd3);
	return (0);
}
