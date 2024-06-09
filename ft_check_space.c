/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abamksa <abamksa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:52:06 by abamksa           #+#    #+#             */
/*   Updated: 2024/06/09 11:00:28 by abamksa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_space(char **av)
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
