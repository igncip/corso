/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:11 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/15 18:26:59 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_return(char	*r_memory)
{
	int		index;
	char	*return_str;

	index = 0;
	if (!r_memory)
		return (NULL);
	while ((r_memory)[index] != '\n' && (r_memory)[index] != '\0')
		index++;
	return_str = (char *) ft_calloc (sizeof(char), index + 1);
	if (!return_str)
	{
		free(return_str);
		return (NULL);
	}
	while (--index >= 0)
		return_str[index] = (r_memory)[index];
	return (return_str);
}

char	*ft_read_buff(char *old_r_buf, int fd)
{
	char	*new_r_buf;
	int		read_num;
	char	*j_str;

	if (ft_strchr (old_r_buf, '\n'))
		return (ft_strcpy (old_r_buf));
	new_r_buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_r_buf)
	{
		free (new_r_buf);
		return ('\0');
	}
	read_num = 1;
	while (!ft_strchr (j_str, '\n') && read_num > 0)
	{
		read_num = read(fd, new_r_buf, BUFFER_SIZE);
		if (read_num < 0)
		{
			free (new_r_buf);
			return ('\0');
		}
		else if (read_num > 0)
		{
			j_str = ft_strjoin(*old_r_buf, new_r_buf);
			free (new_r_buf);
		}
	}
	return (j_str);
}

	/*inserire controllo per file binario nella funzione sotto*/

char	*get_next_line(int fd)
{
	static char	*r_memory;
	char		*return_str;
	char		*r_buf_tmp;

	return_str = ft_free(return_str);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	r_buf_tmp = ft_read_buff (&r_memory, fd);
	if (r_buf_tmp == '\0')
	{
		return (NULL);
	}
	r_memory = ft_free(r_memory);
	return_str = ft_get_return (&r_buf_tmp);
	r_memory = (ft_strchr (r_buf_tmp, '\n'));
	r_buf_tmp = ft_free(r_buf_tmp);
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
