/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_police.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:08:19 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/12 23:34:29 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	take_right_fork(t_table *thinker)
{
	pthread_mutex_lock(thinker->right_fork);
	pthread_mutex_lock(thinker->eaten_lock);
	if (*thinker->dead == 0 && thinker->full == false)
	{
		pthread_mutex_unlock(thinker->eaten_lock);
		print_event(thinker, "has taken a fork");
	}
	else
		pthread_mutex_unlock(thinker->eaten_lock);
}

void	take_left_fork(t_table *thinker)
{
	pthread_mutex_lock(thinker->left_fork);
	pthread_mutex_lock(thinker->eaten_lock);
	if (*thinker->dead == 0 && thinker->full == false)
	{
		pthread_mutex_unlock(thinker->eaten_lock);
		print_event(thinker, "has taken a fork");
	}
	else
		pthread_mutex_unlock(thinker->eaten_lock);
}

void	eat_procedure(t_table *thinker)
{
	pthread_mutex_lock(thinker->eaten_lock);
	if (*thinker->dead == 0 && thinker->full == false)
	{
		pthread_mutex_unlock(thinker->eaten_lock);
		print_event(thinker, "is eating");
		pthread_mutex_lock(thinker->eaten_lock);
		thinker->meals++;
		if (thinker->meals >= thinker->last_meal)
		{
			thinker->full = true;
		}
		thinker->last_meal = get_time();
		pthread_mutex_unlock(thinker->eaten_lock);
		sleep_improved(thinker->time_to_eat);
	}
	else
		pthread_mutex_unlock(thinker->eaten_lock);
}

void	eat(t_table *thinker)
{
	if (thinker->id % 2 == 0)
	{
		take_left_fork(thinker);
		take_right_fork(thinker);
		eat_procedure(thinker);
		pthread_mutex_unlock(thinker->right_fork);
		pthread_mutex_unlock(thinker->left_fork);
	}
	else
	{
		take_right_fork(thinker);
		take_left_fork(thinker);
		eat_procedure(thinker);
		pthread_mutex_unlock(thinker->left_fork);
		pthread_mutex_unlock(thinker->right_fork);
	}
}

void	*dinner_police(void *temp)
{
	t_table	*thinker;

	thinker = (t_table *)temp;
	if (thinker->philo_nbr == 1)
		return (print_event(thinker, "has taken a fork"), sleep_improved(thinker->time_to_die * 1000), NULL);
	pthread_mutex_lock(thinker->eaten_lock);
	while (*thinker->dead == 0 && thinker->full == false)
	{
		pthread_mutex_unlock(thinker->eaten_lock);
		eat(thinker);
		sleeping(thinker);
		pthread_mutex_lock(thinker->eaten_lock);
		if (*thinker->dead == 0 && thinker->full == false)
		{
			pthread_mutex_unlock(thinker->eaten_lock);
			print_event(thinker, "is thinking");
			usleep(1000);
		}
		else
			pthread_mutex_unlock(thinker->eaten_lock);
		pthread_mutex_lock(thinker->eaten_lock);
	}
	pthread_mutex_unlock(thinker->eaten_lock);
	return (NULL);
}
