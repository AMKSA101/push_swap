/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:24:20 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/23 12:08:29 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next(t_stack *stack, int size)
{
	int	i;
	int	len;

	len = ft_lstsize(stack);
	i = 0;
	while (stack)
	{
		if (stack->index <= size)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = (stack)->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	find_max_index(t_stack *stack, int max)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->content == max)
			return (index);
		stack = stack->next;
		index++;
	}
	return (index);
}

int	find_min_index(t_stack *stack, int min)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->content == min)
			return (index);
		stack = stack->next;
		index++;
	}
	return (index);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = (stack)->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
