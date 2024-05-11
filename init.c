/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:56:57 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 21:05:49 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	parse_input(t_table *table, char **argv)
{
	table->philo_nbr = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->meals = ft_atoi(argv[5]);
	else
		table->meals = -1;
	if (table->philo_nbr == 9876543210 || table->time_to_die == 9876543210
		|| table->time_to_eat == 9876543210 || table->time_to_sleep == 9876543210
		|| table->meals == 9876543210)
		return (error_exit("args are overflow integer"), FAILURE);
	if (table->philo_nbr > 200)
		return (FAILURE);
	if (table->philo_nbr < 1)
		return (FAILURE);
	return (OK);
}

int	init_philos(t_data *data, char **argv)
{
	int i;

	i = 0;
	data->dead = 0;
	data->has_eaten = 0;
	if (parse_input(data->thinkers, argv) == FAILURE)
		return (FAILURE);
	while (i < data->thinkers[0].philo_nbr)
	{
		parse_input(&(data->thinkers[i]), argv);
		data->thinkers[i].id = i;
		data->thinkers[i].full = false;
		data->thinkers[i].meals = 0;
		data->thinkers[i].dead = &data->dead;
		data->thinkers[i].print_lock = &data->print_lock;
		data->thinkers[i].eaten_lock = &data->eaten_lock;
		if (pthread_mutex_init(data->thinkers[i].eaten_lock, NULL) != 0)
			return (destroy_forks(data->thinkers, i), error_exit("mutex eaten_lock failed"), FAILURE);
		if (i != 0)
			data->thinkers[i].left_fork = data->thinkers[i - 1].right_fork;
		i++;
	}
	data->thinkers[0].left_fork = data->thinkers[data->thinkers[0].philo_nbr - 1].right_fork;
	return (OK);
}
