/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:38:00 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/23 15:05:53 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;
	char	*result;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	result = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (result);
}

char	*ft_joinstr(char *buffer, const char *content)
{
	size_t	buffer_len;
	size_t	content_len;
	char	*result;
	char	*ptr;
	char	*tmp;

	buffer_len = 0;
	if (!buffer && !content)
		return (NULL);
	if (buffer)
		buffer_len = ft_strlen(buffer);
	content_len = ft_strlen(content);
	result = (char *)malloc(sizeof(char) * (buffer_len + content_len + 1));
	if (!result)
		return (NULL);
	ptr = result;
	tmp = buffer;
	while (tmp && *tmp)
		*ptr++ = *tmp++;
	tmp = (char *)content;
	while (tmp && *tmp)
		*ptr++ = *tmp++;
	*ptr = '\0';
	free(buffer);
	return (result);
}
