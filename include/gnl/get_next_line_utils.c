/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqureshi <hqureshi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:52:09 by hqureshi          #+#    #+#             */
/*   Updated: 2022/03/16 10:52:10 by hqureshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_char(char *string, int c)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
	{
		if (string[i] == (char) c)
		{
			return ((char *)&string[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*dest;

	if (!s)
		return (0);
	s_len = ft_gnl_strlen(s);
	dest = (char *)malloc(len + 1);
	if (!dest)
	{
		free(dest);
		return (0);
	}
	i = start;
	j = 0;
	while (j < len && s_len >= start)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	int		count;
	char	*src_char;
	char	*dest_char;

	src_char = (char *) src;
	dest_char = (char *) dest;
	count = 0;
	if (dest == src)
		return (dest_char);
	while (num--)
	{
		dest_char[count] = src_char[count];
		count++;
	}
	return (dest_char);
}

char	*ft_gnl_strdup(const char *s1)
{
	char	*ptr;
	int		size;

	size = ft_gnl_strlen(s1) + 1;
	ptr = malloc(size);
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr)
		ft_memcpy(ptr, s1, size);
	return (ptr);
}
