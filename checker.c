/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:29:48 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/09 11:01:53 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_line(char *line, t_stack **lst, t_stack **stack)
{
	if (!ft_strcmp(line, "sa"))
		sa(lst, 0);
	else if (!ft_strcmp(line, "sb"))
		sb(stack, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(lst, stack, 0);
	else if (!ft_strcmp(line, "pa"))
		pa(stack, lst, 0);
	else if (!ft_strcmp(line, "pb"))
		pb(lst, stack, 0);
	else if (!ft_strcmp(line, "ra"))
		ra(lst, 0);
	else if (!ft_strcmp(line, "rb"))
		rb(stack, 0);
	else if (!ft_strcmp(line, "rra"))
		rra(lst, 0);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack, 0);
	else if (!ft_strcmp(line, "rrr"))
		rrr(lst, stack, 0);
	else if (!ft_strcmp(line, "rr"))
		rr(lst, stack, 0);
	else
		return (1);
	return (0);
}

void	free_and_exit(t_stack **lst, t_stack **stack, char *line)
{
	ft_lstclear(*lst);
	ft_lstclear(*stack);
	free(line);
	error_message();
}

void	ft_operate(t_stack **lst)
{
	char	*line;
	t_stack	*stack;

	stack = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (line == 0)
			break ;
		if (ft_check_line(line, lst, &stack))
			free_and_exit(lst, &stack, line);
		free(line);
	}
	if (!check_sort(*lst) && !stack)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(*lst);
	ft_lstclear(stack);
	exit(0);
}

void	t_stack_init(t_stack **a, char **av, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av, av[i], NULL)));
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	ft_operate(a);
}

int	main(int ac, char *av[])
{
	static int	i;
	t_stack		*a;
	char		*result;

	a = NULL;
	result = NULL;
	if (ac == 1)
		return (1);
	else if ((ac == 2 && !av[1][0]))
		error_message();
	else
	{
		ft_check_space(++av);
		i = -1;
		while (++i < ac - 1)
			result = ft_strjoin(result, av[i]);
		av = ft_split(result, ' ');
		free(result);
		i = 0;
		while (av[i])
			i++;
		check_args(av, i);
		t_stack_init(&a, av, i);
	}
	return (0);
}
