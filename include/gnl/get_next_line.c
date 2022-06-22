/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:52:03 by hqureshi          #+#    #+#             */
/*   Updated: 2022/04/01 12:58:52 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_gnl_strlen(s1) + \
	ft_gnl_strlen(s2) + 1);
	if (dest == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			dest[i] = s1[i];
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[ft_gnl_strlen(s1) + ft_gnl_strlen(s2)] = '\0';
	free(s1);
	return (dest);
}

char	*ft_rewrite_string(char *string)
{
	int		i;
	char	*temp;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
		{
			temp = ft_gnl_strdup(&string[i + 1]);
			free(string);
			return (temp);
		}
		i++;
	}
	if (!string[i])
	{
		free(string);
		return (NULL);
	}
	return (0);
}

char	*get_string_line(char *string)
{
	char	*tmp;
	int		i;

	i = 0;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	while (string[i] != '\n' && string[i] != '\0')
	{
		i++;
	}
	tmp = ft_substr(string, 0, i + 1);
	if (!tmp)
	{
		return (NULL);
	}
	return (tmp);
}

char	*ft_read_lines(int fd, char *string)
{
	char	buff[BUFFER_SIZE + 1];
	int		string_len;

	string_len = 1;
	buff[0] = '\0';
	while (!ft_find_char(buff, '\n') && string_len != 0)
	{
		string_len = read(fd, buff, BUFFER_SIZE);
		if (string_len == -1)
		{
			return (NULL);
		}
		buff[string_len] = '\0';
		string = ft_gnl_strjoin(string, buff);
	}
	if (!string[0])
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char	*get_next_line(int fd)
{
	static char		*string;
	char			*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = ft_read_lines(fd, string);
	if (!string)
		return (NULL);
	return_line = get_string_line(string);
	if (!return_line)
		return (NULL);
	string = ft_rewrite_string(string);
	return (return_line);
}
