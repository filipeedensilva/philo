/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:47:05 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/05 19:35:12 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	error_msg(void)
{
	printf("Invalid arguments!\n");
	return (0);
}

int	check_args(void)
{
	int	flag;

	flag = 1;
	if (!is_allowed(data()->num_philos))
		flag = error_msg();
	else if (!is_allowed(data()->time_die))
		flag = error_msg();
	else if (!is_allowed(data()->time_eat))
		flag = error_msg();
	else if (!is_allowed(data()->time_sleep))
		flag = error_msg();
	else if (data()->num_times_eat != '\2'\
		&& !is_allowed(data()->num_times_eat))
		flag = error_msg();
	return (flag);
}

void	parse_args(int ac, char **av)
{
	if (ac == 5)
	{
		data()->num_philos = ft_atoi(av[1]);
		data()->time_die = ft_atoi(av[2]);
		data()->time_eat = ft_atoi(av[3]);
		data()->time_sleep = ft_atoi(av[4]);
		data()->num_times_eat = '\2';
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
		printf("Wrong number of arguments!\nUsage: ./philo 'number_of_philosophers' 'time_to_die' 'time_to_eat' 'time_to_sleep' '[number_of_times_each_philosopher_must_eat]'\n");
}
