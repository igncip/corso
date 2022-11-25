/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:11 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/21 22:36:12 by igncipri         ###   ########.fr       */
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

char	*ft_strlcpymod(char *src, size_t size)
{
	size_t	index;
	char	*dst;

	index = 0;
	if (size == 0)
		return (NULL);
	if (ft_strlen(src) < size)
		dst = ft_calloc((ft_strlen(src) + 1), sizeof(char));
	else
		dst = ft_calloc(size + 1, sizeof(char));
	while (index < size - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_get_buff(char *old_str, int fd)
{
	char	*r_buff;
	char	*join_str;
	int		r_num;

	join_str = NULL;
	join_str = ft_strlcpymod (old_str, ft_strlen(old_str));
	old_str = ft_free(old_str);
	r_buff = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	while (!ft_strchr(join_str, '\n'))
	{
		r_num = read(fd, r_buff, BUFFER_SIZE);
		if (r_num > 0)
			join_str = ft_strjoinevo(join_str, r_buff, 1);
		else if (r_num < 0)
		{
			r_buff = ft_free(r_buff);
			return (join_str = ft_free(join_str));
		}
	}
	r_buff = ft_free(r_buff);
	return (join_str);
}

char	*ft_get_return(char	*full_str)
{
	char	*return_str;
	char	*temp;

	return_str = NULL;
	if (!full_str)
		return (NULL);
	temp = ft_strchr(full_str, '\n');
	if (!temp)
	{
		return_str = ft_strlcpymod (full_str, ft_strlen(full_str));
		return (return_str);
	}
	return_str = ft_strlcpymod (temp, ft_strlen(temp));
	ft_free(temp);
	return (return_str);
}

char	*get_next_line(int fd)
{
	static char	*old_str;
	char		*new_str;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new_str = ft_get_buff(old_str, fd);
	old_str = ft_free(old_str);
	if (!new_str)
		return (new_str = ft_free(new_str));
	return_str = ft_get_return(new_str);
	if (return_str == new_str)
		old_str = NULL;
	else
		old_str = ft_strlcpymod((ft_strchr(new_str, '\n')),
			(ft_strlen(ft_strchr(new_str, '\n'))));
	new_str = ft_free(new_str);
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