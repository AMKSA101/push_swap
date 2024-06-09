/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:22:42 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/06 09:29:06 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_range_check(t_stack **stack, t_stack *stack_b, int len)
{
	int	range;

	range = 0;
	if (len < 6)
	{
		sort_min(stack, &stack_b);
		return (0);
	}
	if (len <= 10)
		range = 5;
	else if (len <= 100)
		range = 15;
	else
		range = 30;
	return (range);
}

void	sort_stack(t_stack **a)
{
	t_stack	*b;
	int		range;
	int		*arr;
	int		len;
	int		i;

	len = ft_lstsize(*a);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
	{
		error_message();
		return ;
	}
	stack_array(*a, arr, len);
	set_index(*a, arr);
	free(arr);
	b = NULL;
	i = 0;
	if (!check_sort(*a))
		return ;
	range = ft_range_check(a, b, len);
	if (range == 0)
		return ;
	sort_algo(a, &b, len, range);
}

void	stack_init(t_stack **a, char **av, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		ft_lstadd_back(a, ft_lstnew(ft_atoi(NULL, av[i], NULL)));
	sort_stack(a);
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	ft_lstclear(*a);
}

void	check_space(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && !(av[i][j] >= 9 && av[i][j] <= 13))
				break ;
			j++;
			if (av[i][j] == '\0')
				error_message();
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*a;
	char	*result;

	i = -1;
	a = NULL;
	result = NULL;
	if (ac == 1)
		return (1);
	else if ((ac == 2 && !av[1][0]))
		error_message();
	else
	{
		check_space(++av);
		while (++i < ac - 1)
			result = ft_strjoin(result, av[i]);
		av = ft_split(result, ' ');
		free(result);
		i = 0;
		while (av[i])
			i++;
		check_args(av, i);
		stack_init(&a, av, i);
	}
}
