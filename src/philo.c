/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:04:54 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/15 18:00:14 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eating_action(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->right_fork]);
		write_msg(data, philo->id, "picked up a fork");
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		write_msg(data, philo->id, "picked up a fork");
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->left_fork]);
		write_msg(data, philo->id, "picked up a fork");
		pthread_mutex_lock(&data->forks[philo->right_fork]);
		write_msg(data, philo->id, "picked up a fork");
	}
	write_msg(data, philo->id, "is eating");
	pthread_mutex_lock(&data->death_check);
	philo->last_meal = get_time();
	philo->num_meals++;
	pthread_mutex_unlock(&data->death_check);
	usleep(data->time_eat * 1000);
	pthread_mutex_unlock(&data->forks[philo->left_fork]);
	pthread_mutex_unlock(&data->forks[philo->right_fork]);
}

void	*routine(void *philoo)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)philoo;
	data = philo->data;
	if (data->num_philos == 1)
		return (write_msg(data, philo->id, "has taken a fork"), NULL);
	while (!check_death_flag(data))
	{
		eating_action(data, philo);
		if (philo->num_meals == data->num_times_eat)
			break ;
		write_msg(data, philo->id, "is sleeping");
		usleep(data->time_sleep * 1000);
		write_msg(data, philo->id, "is thinking");
		usleep(ft_abs(data->time_eat - data->time_sleep) * 1000);
		usleep(400);
	}
	return (NULL);
}

void	checking_threads(t_data *data, t_philo *philo)
{
	int	i;

	while (!check_death_flag(data))
	{
		i = -1;
		while (++i < data->num_philos && !check_death_flag(data))
		{
			if (check_all_ate(data, philo))
				return ;
			pthread_mutex_lock(&data->death_check);
			if (get_time() - philo[i].last_meal >= \
				(long long unsigned int) data->time_die)
			{
				write_msg(data, philo->id, "died");
				pthread_mutex_lock(&data->write);
				data->death_flag = 1;
				pthread_mutex_unlock(&data->write);
				pthread_mutex_unlock(&data->death_check);
				return ;
			}
			else
				pthread_mutex_unlock(&data->death_check);
		}
	}
}

void	join_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < data->num_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->death_check);
}

int	init_threads(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = data->philos;
	data->start = get_time();
	while (++i < data->num_philos)
	{
		if (pthread_create(&(philo[i].thread), NULL, routine, &(philo[i])))
		{
			printf("Error initializing threads!\n");
			return (1);
		}
		pthread_mutex_lock(&data->death_check);
		philo[i].last_meal = get_time();
		pthread_mutex_unlock(&data->death_check);
	}
	checking_threads(data, philo);
	join_threads(data, philo);
	return (0);
}
