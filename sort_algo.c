/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:22:45 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/23 11:27:30 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content < stack->next->content)
		{
			stack = stack->next;
			continue ;
		}
		else
			return (1);
	}
	return (0);
}

void	sort_min(t_stack **a, t_stack **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = find_min(*a);
		if ((*a)->content == min)
			pb(a, b, 1);
		else if (find_min_index(*a, min) <= ft_lstsize(*a) / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	while (ft_lstsize(*a) <= 3)
	{
		if (!check_sort(*a))
			break ;
		if ((*a)->content > (*a)->next->content)
			sa(a, 1);
		else
			rra(a, 1);
	}
	while (*b)
		pa(b, a, 1);
}

void	last_move(t_stack **a, t_stack **b)
{
	int	max;

	while (*b)
	{
		max = find_max(*b);
		if ((*b)->content == max)
			pa(b, a, 1);
		else if (find_max_index(*b, max) <= ft_lstsize(*b) / 2)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

void	sort_algo(t_stack **a, t_stack **b, int len, int range)
{
	int	size;

	size = 0;
	while (*a)
	{
		if ((*a)->index <= size)
		{
			pb(a, b, 1);
			rb(b, 1);
			size++;
		}
		else if ((*a)->index <= size + range)
		{
			pb(a, b, 1);
			size++;
		}
		else if (find_next(*a, size + range) <= len / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	while (*b)
		last_move(a, b);
}
