/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmillan <dmillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 06:43:47 by dmillan           #+#    #+#             */
/*   Updated: 2022/06/23 00:18:29 by dmillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_trim_buffer(char *buffer)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = NULL;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buff = ft_substr(buffer, i + 1, ft_strlen(buffer) - i - 1);
	if (!new_buff)
		return (NULL);
	free(buffer);
	return (new_buff);
}

static char	*ft_read_line(char *buffer)
{
	size_t	i;
	char	*line;

	if (!(*buffer))
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line = ft_memcpy(line, buffer, i);
	line[i] = '\0';
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp;
	int		read_pt;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_pt = 1;
	printf("check2!");
	while (read_pt > 0 && !ft_strchr(buffer, (int) '\n'))
	{
		read_pt = read(fd, tmp, BUFFER_SIZE);
		if (read_pt < 0)
		{
			free(tmp);
			return (buffer);
		}
		else
		{
			tmp[read_pt] = '\0';
			buffer = ft_strjoin(buffer, tmp);
		}
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = ft_trim_buffer(buffer);
	return (line);
}
