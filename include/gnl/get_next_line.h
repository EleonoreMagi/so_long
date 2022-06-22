/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 06:42:16 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/23 00:35:56 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
void	*ft_gnl_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnl_strchr(const char *s, int c);
size_t	ft_gnl_strlen(const char *s);
#endif