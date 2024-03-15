/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:18 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/15 18:00:21 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	parse_args(&data, ac, av);
	if (check_args(&data))
		return (1);
	if (init(&data))
		return (2);
	if (init_threads(&data))
		return (3);
	return (0);
}
