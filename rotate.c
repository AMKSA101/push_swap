/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:23:05 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/23 14:58:01 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_stack **stack, int flag)
{
	rotate(stack);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int flag)
{
	rotate(stack);
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (flag)
		write(1, "rr\n", 3);
}
