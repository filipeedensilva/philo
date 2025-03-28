/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:26:28 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/15 17:40:32 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_t			thread;
	int					id;
	int					right_fork;
	int					left_fork;
	int					num_meals;
	unsigned long long	last_meal;
	t_data				*data;
};

struct	s_data
{
	long			num_philos;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			num_times_eat;
	long			death_flag;
	long long		start;
	pthread_mutex_t	write;
	pthread_mutex_t	death_check;
	pthread_mutex_t	forks[250];
	t_philo			philos[250];
};

// Parsing arguments
void				parse_args(t_data *data, int ac, char **av);
int					check_args(t_data *data);

// Parsing utils
long				ft_atol(char *str);
int					is_allowed(long num);

// Struct functions
t_data				*data(void);
int					init(t_data *data);

// Time function
unsigned long long	get_time(void);

// Write function
void				write_msg(t_data *data, int philo, char *action);

//  Utils
int					check_death_flag(t_data *data);
int					ft_abs(int num);
int					check_all_ate(t_data *data, t_philo *philo);

// Initiazlize threads
int					init_threads(t_data *data);

#endif
