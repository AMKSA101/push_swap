/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:07:37 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/09 20:27:10 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **av, int *arr)
{
	int	i;

	i = 0;
	free(arr);
	while (av[i])
		free(av[i++]);
	free(av);
	error_message();
}

long	ft_clean(char **av, const char *nptr, int *arr, long long res)
{
	while (*nptr >= '0' && *nptr <= '9')
	{
		if ((*nptr < '0' && *nptr > '9'))
			ft_error(av, arr);
		res = res * 10 + (*nptr - 48);
		++nptr;
	}
	while ((*nptr >= '\t' && *nptr <= '\r') || (*nptr == ' '))
	{
		++nptr;
		if (*nptr == '\0' && !res)
			ft_error(av, arr);
	}
	if (*nptr >= '0' && *nptr <= '9')
	{
		ft_clean(av, nptr, arr, res);
		return (res);
	}
	if ((*nptr > 31 && *nptr < 127))
		ft_error(av, arr);
	return (res);
}

int	ft_atoi(char **av, const char *nptr, int *arr)
{
	long long	res;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || (*nptr == ' '))
	{
		++nptr;
		if (*nptr == '\0')
			ft_error(av, arr);
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		++nptr;
		if (!*nptr)
			ft_error(av, arr);
	}
	res = ft_clean(av, nptr, arr, res);
	if (res * sign > 2147483647 || res * sign < -2147483648)
		ft_error(av, arr);
	return (res * sign);
}

void	check_duplicate(char **argv, int *av, int size)
{
	int	i;
	int	j;

	i = 0;
	if (!av)
		error_message();
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (av[i] == av[j])
				ft_error(argv, av);
			j++;
		}
		i++;
	}
}

void	check_args(char **av, int size)
{
	int	i;
	int	*arr;

	if (!*av)
		return ;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
	{
		error_message();
		return ;
	}
	i = -1;
	while (++i < size)
		arr[i] = ft_atoi(av, av[i], arr);
	if (i > 1)
		check_duplicate(av, arr, size);
	free(arr);
}
