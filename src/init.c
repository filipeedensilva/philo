/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:37:03 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/06 17:55:15 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>

void	print_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		printf("\nPhilo id: %d\n", data->philos[i].id);
		printf("Left fork id: %d\n", data->philos[i].left_fork);
		printf("Right fork id: %d\n", data->philos[i].right_fork);
		i++;
	}
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(data->write), NULL))
		return (1);
	if (pthread_mutex_init(&(data->death_check), NULL))
		return (1);
	return (0);
}

void	init_philo(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = 0;
		data->philos[i].left_fork = i + 1;
		if (data->num_philos != 1)
		{
			if (i == data->num_philos - 1)
				data->philos[i].right_fork = 1;
			else
				data->philos[i].right_fork = i + 2;
		}
		data->philos[i].data = data;
		i++;
	}
	print_philos(data);
}

int	init(t_data *data)
{
	if (init_mutex(data))
	{
		printf("Error in creating mutexes!\n");
		return (1);
	}
	init_philo(data);
	return (0);
}
