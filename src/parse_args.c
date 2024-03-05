/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:47:05 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/05 19:12:07 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	error_msg(void)
{
	printf("Invalid arguments!\n");
}

int	check_args(void)
{
	if (!is_allowed(data()->num_philos))
		error_msg();
	else if (!is_allowed(data()->time_die))
		error_msg();
	else if (!is_allowed(data()->time_eat))
		error_msg();
	else if (!is_allowed(data()->time_sleep))
		error_msg();
	else if (data()->num_times_eat != -1 && !is_allowed(data()->num_times_eat))
		error_msg();
	return (0);
}

int	parse_args(int ac, char **av)
{
	if (ac == 5)
	{
		data()->num_philos = ft_atoi(av[1]);
		data()->time_die = ft_atoi(av[2]);
		data()->time_eat = ft_atoi(av[3]);
		data()->time_sleep = ft_atoi(av[4]);
		data()->num_times_eat = -1;
	}
	else if (ac == 6)
	{
		data()->num_philos = ft_atoi(av[1]);
		data()->time_die = ft_atoi(av[2]);
		data()->time_eat = ft_atoi(av[3]);
		data()->time_sleep = ft_atoi(av[4]);
		data()->num_times_eat = ft_atoi(av[5]);
	}
	else
	{
		printf("Wrong number of arguments!\nUsage: ./philo 'number_of_philosophers' 'time_to_die' 'time_to_eat' 'time_to_sleep' '[number_of_times_each_philosopher_must_eat]'\n");
	}
	check_args();
	return (0);
}

