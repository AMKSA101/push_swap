/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:22:58 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/21 15:04:59 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	if (!*stack_b)
	{
		*stack_b = tmp;
		*stack_a = tmp->next;
		tmp->next = NULL;
	}
	else
	{
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag)
		write(1, "pb\n", 3);
}
