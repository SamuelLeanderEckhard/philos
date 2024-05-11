/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:26:27 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 21:10:48 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	print_event(t_table *thinker, char *event)
{
	pthread_mutex_lock(thinker->print_lock);
	printf("%ld %ld %d %s\n", get_time() - thinker->last_meal, thinker->id, *thinker->dead, event);
	pthread_mutex_unlock(thinker->print_lock);
	return (OK);
}

int check_death(t_data *data)
{
	int i;

	i = 0;
	while (i < data->thinkers[0].philo_nbr)
	{
		pthread_mutex_lock(data->thinkers[i].eaten_lock);
		if (get_time() - data->thinkers[i].last_meal > data->thinkers[i].time_to_die)
		{
			*data->thinkers[i].dead = 1;
			if (data->has_eaten < data->thinkers[i].philo_nbr)
				print_event(&data->thinkers[i], "died");
			pthread_mutex_unlock(data->thinkers[i].eaten_lock);
			return (FAILURE);
		}
		pthread_mutex_unlock(data->thinkers[i].eaten_lock);
		i++;
	}
	return (OK);
}

int	dinner_party(t_data *data)
{
	int i;

	i = 0;
	while (++i < data->thinkers[0].philo_nbr)
	{
		data->thinkers[i].start = get_time();
		data->thinkers[i].last_meal = data->thinkers[i].start;
		if (pthread_create(&data->thinkers[i].philos, NULL, &dinner_police, &data->thinkers[i]) != 0)
		{
			destroy_philos(data);
			return (error_exit("creating thread unsuccessful"), FAILURE);
		}
		i++;
	}
	while (1)
	{
		if (check_death(data) == FAILURE)
			break ;
	}
	i = -1;
	while (++i < data->thinkers[0].philo_nbr)
		pthread_join(data->thinkers[i].philos, NULL);
	// destroy_philos(data);
	return (OK);
}
