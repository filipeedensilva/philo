/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:18 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/06 17:31:40 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*data(void)
{
	static t_data	data;
	return (&data);
}

int	main(int ac, char **av)
{
	t_data	data;
	parse_args(&data, ac, av);
	if (check_args(&data))
		return (1);
	if (init(&data))
		return (2);
	return (0);
}
