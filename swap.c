/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:23:11 by abamksa           #+#    #+#             */
/*   Updated: 2024/05/22 15:57:17 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	(*lst)->index = 0;
	tmp->index = 1;
}

void	sa(t_stack **stack_a, int flag)
{
	swap(stack_a);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int flag)
{
	swap(stack_b);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **s_tack_b, int flag)
{
	swap(stack_a);
	swap(s_tack_b);
	if (flag)
		write(1, "ss\n", 3);
}
