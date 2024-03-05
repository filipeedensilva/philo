/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:37:03 by feden-pe          #+#    #+#             */
/*   Updated: 2024/03/05 19:51:48 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*find_tail(t_philo *head)
{
	t_philo	*current;

	if (!head)
		return (NULL);
	current = head;
	while (current->next)
		current = current->next;
	return (current);
}

void	add_node(t_philo **head, int index)
{
	t_philo	*new;
	t_philo	*current;

	new = malloc(sizeof(t_philo));
	new->id = ++index;
	if (!*head)
	{
		*head = new;
		return ;
	}
	current = find_tail(*head);
	current->next = new;
}

void	print_philos(t_philo *head)
{
	t_philo	*current;

	current = head;
	while (current)
	{
		printf("ID: %d\n", current->id);
		current = current->next;
	}
}

void	init_struct(void)
{
	t_philo	*head;
	int		i;

	i = 0;
	head = NULL;
	while (i < data()->num_philos)
	{
		add_node(&head, i);
		i++;
	}
	print_philos(head);
}
