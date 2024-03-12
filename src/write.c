/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:17:12 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/12 19:29:34 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	write_msg(t_data *data, int philo, char *action)
{
	pthread_mutex_lock(&data->write);
	if (!data->death_flag)
	{
		printf("%lli ", get_time() - data->start);
		printf("%d %s\n", philo, action);
	}
	pthread_mutex_unlock(&data->write);
}

int	check_death_flag(t_data *data)
{
	int	flag;

	pthread_mutex_lock(&data->death_check);
	flag = data->death_flag;
	pthread_mutex_unlock(&data->death_check);
	return (flag);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	check_all_ate(t_data *data, t_philo *philo)
{
	int	i;
	int	meals_eaten;

	i = 0;
	meals_eaten = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->death_check);
		if (philo[i].num_meals == data->num_times_eat)
			meals_eaten++;
		pthread_mutex_unlock(&data->death_check);
		if (meals_eaten == data->num_philos)
			return (1);
		i++;
	}
	return (0);
}
