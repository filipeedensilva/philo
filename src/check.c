/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:40:57 by feden-pe          #+#    #+#             */
/*   Updated: 2023/11/24 12:04:26 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 5)
	{
		while (av[i])
		{
			if (!is_num(av[i]))
				printf("Error: argument is not a number!\n");
			i++;
		}
	}
	else if (ac == 6)
	{
		while (av[i])
		{
			if (!is_num(av[i]))
				printf("Error: argument is not a number!\n");
			i++;
		}
	}
	else
		printf("Error: wrong number of arguments!\n");
}
