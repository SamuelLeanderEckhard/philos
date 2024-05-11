/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_police.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:08:19 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 19:30:49 by seckhard         ###   ########.fr       */
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

void	sleep_improved(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
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


void	*dinner_police(void *temp)
{
	t_table	*thinker;

	thinker = (t_table *)temp;
	while (1)
	{
		take_left_fork(thinker);
		take_right_fork(thinker);
		eat_procedure(thinker);
		if (thinker->full == true)
			break ;
		print_event(thinker, "is sleeping");
		sleep_improved(thinker->time_to_sleep);
		print_event(thinker, "is thinking");
	}
	return (OK);
}
