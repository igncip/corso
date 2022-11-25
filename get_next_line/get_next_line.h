/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igncipri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:15:01 by igncipri          #+#    #+#             */
/*   Updated: 2022/11/21 22:35:55 by igncipri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strlcpymod(char *src, size_t size);
char	*ft_free(char *str);
char	*ft_strjoinevo(char *s1, char *s2, int fr);
char	*ft_strchr(char *s, int c);
char	*ft_get_return(char	*full_str);
char	*ft_read_buff(char *old_str, int fd);
char	*get_next_line(int fd);

#endif
