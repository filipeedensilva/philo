/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:56:32 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/13 15:51:07 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	philo_starved(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->death_check);
	if (get_time() - philo->last_meal >= data->time_die)
	{
		if (!data->death_flag)
		{
			write_msg(data, philo->id, "\033[1;31mdied\033[0m");
			data->death_flag = 1;
			pthread_mutex_unlock(&data->death_check);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->death_check);
	return (0);
}
