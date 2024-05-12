/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:00:10 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/12 18:47:40 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	error_exit(const char *error)
{
	printf("%s\n", error);
	exit(FAILURE);
}

void	destroy_mutex(pthread_mutex_t *mutex, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&mutex[i]);
		i--;
	}
}

void	destroy_forks(t_table *table, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&table->right_fork[i--]);
	}
	pthread_mutex_destroy(table->print_lock);
	pthread_mutex_destroy(table->eaten_lock);
}

void	destroy_philos(t_data *data, int i)
{
	destroy_forks(data->thinkers, data->thinkers->philo_nbr);
	while (i >= 0)
	{
		pthread_join(data->thinkers[i].philos, NULL);
		i--;
	}
}
