/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:23:01 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/22 16:12:35 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack || ft_lstsize(*stack) < 2)
		return ;
	tmp2 = ft_beflastlst(*stack);
	tmp = ft_lastlst(*stack);
	tmp2->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_stack **stack, int flag)
{
	rev_rotate(stack);
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack, int flag)
{
	rev_rotate(stack);
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (flag)
		write(1, "rrr\n", 4);
}
