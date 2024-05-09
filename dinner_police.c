/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_police.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:08:19 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 23:21:19 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	dinner_police(t_table *thinker)
{
	while (1)
	{
		if (thinker->full == true)
			break ;
		pthread_mutex_lock(thinker->left_fork);
		if (print_event(thinker, "has taken a fork") == FAILURE)
			break ;
		pthread_mutex_lock(thinker->right_fork);
		if (print_event(thinker, "has taken a fork") == FAILURE)
			break ;
		if (print_event(thinker, "is eating") == FAILURE)
			break ;
		thinker->last_meal = get_time();
		thinker->meals++;
		pthread_mutex_unlock(thinker->left_fork);
		pthread_mutex_unlock(thinker->right_fork);
		if (thinker->meals == thinker->meals)
			thinker->full = true;
		if (print_event(thinker, "is sleeping") == FAILURE)
			break ;
		usleep(thinker->time_to_sleep * 1000);
		if (print_event(thinker, "is thinking") == FAILURE)
			break ;
	}
}
