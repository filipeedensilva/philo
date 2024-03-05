/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:27:18 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/05 19:51:26 by feden-pe         ###   ########.fr       */
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
	parse_args(ac, av);
	if (!check_args())
		return (1);
	init_struct();
	return (0);
}
