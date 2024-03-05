/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:26:28 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/05 19:02:54 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_data
{
	int	num_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_times_eat;
}		t_data;

// Parsing arguments
int		parse_args(int ac, char **av);
int		ft_atoi(char *str);
int		is_allowed(int num);

// Struct functions
t_data	*data(void);

#endif
