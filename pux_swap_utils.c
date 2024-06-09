/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pux_swap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:21:04 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/09 11:02:05 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	indx;

	indx = 0;
	while (str[indx])
		indx++;
	return (indx);
}

t_stack	*ft_beflastlst(t_stack *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lastlst(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	set_index(t_stack *stack, int arr[])
{
	int	i;
	int	*ptr;

	while (stack)
	{
		i = 0;
		ptr = arr;
		while (stack->content != *ptr && ++i)
			ptr++;
		if (stack->content == *ptr)
			stack->index = i;
		stack = stack->next;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!*s2 && *(++s1) == '\n')
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
