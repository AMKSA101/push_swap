/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:45:08 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/23 14:44:54 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_join(char const *s1, char const *s2, char *str_new)
{
	if (s1)
	{
		while (*s1)
			*str_new++ = *s1++;
		*str_new++ = ' ';
	}
	while (*s2)
		*str_new++ = *s2++;
	*str_new = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;
	char	*fs1;
	char	*str_new;

	s1_len = 0;
	s2_len = 0;
	fs1 = (char *)s1;
	if (!s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!str_new)
		return (NULL);
	ptr = str_new;
	ft_join(s1, s2, str_new);
	if (fs1)
		free(fs1);
	return (ptr);
}

void	ft_swap(int *arr1, int *arr2)
{
	int	tmp;

	tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

void	stack_array(t_stack *a, int arr[], int len)
{
	static int	i;
	int			j;

	while (a)
	{
		arr[i++] = (a)->content;
		a = (a)->next;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] >= arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		while (--j > i + 1)
		{
			if (arr[j] <= arr[j - 1])
				ft_swap(&arr[j], &arr[j - 1]);
		}
		i += 2;
	}
}
