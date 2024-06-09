/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:29:00 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/23 15:05:55 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	get_line_break(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = str;
	while (*(ptr + i) && *(ptr + i) != '\n')
		i++;
	if (*(ptr + i) == '\n')
		i++;
	return (i);
}

static char	*make_substring(char *str)
{
	char	*substr;
	size_t	pos;
	size_t	j;

	pos = 0;
	j = 0;
	if (!*str)
		return (free(str), NULL);
	pos = get_line_break(str);
	substr = (char *)malloc((ft_strlen(str) - pos) + 1);
	if (!substr)
		return (free(substr), NULL);
	while (*(str + pos))
		*(substr + j++) = *(str + pos++);
	*(substr + j) = '\0';
	if (!*substr)
		return (free(str), free(substr), NULL);
	free(str);
	return (substr);
}

static char	*get_line(char *str)
{
	char	*line;
	size_t	i;

	if (!str || *str == '\0')
		return (NULL);
	i = get_line_break(str);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*(str + i) && *(str + i) != '\n')
	{
		*(line + i) = *(str + i);
		i++;
	}
	if (*(str + i) == '\n')
	{
		*(line + i) = *(str + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}

static char	*free_malloc(char *first_buffer, char *second_buffer)
{
	free(first_buffer);
	free(second_buffer);
	second_buffer = NULL;
	return (second_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*content;
	ssize_t		nb_bytes;

	nb_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!content)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && nb_bytes != 0)
	{
		nb_bytes = read(fd, content, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			buffer = free_malloc(content, buffer);
			return (NULL);
		}
		*(content + nb_bytes) = '\0';
		buffer = ft_strjoin(buffer, content);
	}
	free(content);
	content = get_line(buffer);
	buffer = make_substring(buffer);
	return (content);
}
