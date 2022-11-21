/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:11 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/21 18:48:27 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		index;
	char	c_conv;

	c_conv = (char)c;
	index = 0;
	if (!s)
		return (NULL);
	while (s[index] != '\0')
	{
		if (s[index] == (c_conv))
			return (&(s[index]));
		index++;
	}
	if ((c_conv) == '\0')
		return (&(s[index]));
	return (NULL);
}

char	*ft_get_return(char	*full_str)
{
	int		index;
	char	*return_str;

	index = 0;
	if (!full_str)
		return (NULL);
	while ((full_str)[index] != '\n' && (full_str)[index] != '\0')
		index++;
	return_str = (char *) ft_calloc (index + 1, sizeof(char));
	if (!return_str)
	{
		return_str = ft_free(return_str);
		return (return_str = ft_free(return_str));
	}
	while (--index >= 0)
		return_str[index] = (full_str)[index];
	return (return_str);
}

char	*ft_read_buff(char *old_j_str, int fd)
{
	char	*j_str;
	char	*new_r_buf;
	int		r_num;

	r_num = 1;
	new_r_buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_r_buf)
		return (new_r_buf = ft_free (new_r_buf));
	if (ft_strchr(old_j_str, '\n'))
		j_str = ft_strjoinevo(old_j_str, "", 1, 0);
	else
	{
		j_str = old_j_str;
		while ((ft_strchr(j_str, '\n')) && r_num > 0)
		{
			r_num = read(fd, new_r_buf, BUFFER_SIZE);
			j_str = ft_strjoinevo(j_str, new_r_buf, 1, 0);
		}
	}
	new_r_buf = ft_free(new_r_buf);
	if (r_num < 0)
		return (j_str = ft_free(j_str));
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
		r_memory = ft_free(r_memory);
		return_str = ft_free(return_str);
		return (r_buf_tmp = ft_free(r_buf_tmp));
	}
	r_memory = ft_free(r_memory);
	return_str = ft_get_return (&r_buf_tmp);
	r_memory = (ft_strchr (r_buf_tmp, '\n'));
	r_buf_tmp = ft_free(r_buf_tmp);
	return (return_str);
}

/*TEST SECTION
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
*/