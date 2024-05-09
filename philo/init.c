/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:56:57 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 18:16:26 by seckhard         ###   ########.fr       */
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
	// perhaps add overflow check here
	if (table->philo_nbr > 200)
		return (FAILURE);
	if (table->philo_nbr < 1)
		return (FAILURE);
	return (OK);
}

void	init_philos(t_data *data, char **argv)
{
	int i;

	i = 0;
	data->dead = 0;
	data->has_eaten = 0;
	if (parse_input(&data->thinkers, argv) == FAILURE)
		return (FAILURE);
	while (i < data->thinkers[0].philo_nbr)
	{
		parse_input(&data->thinkers[i], argv);
		data->thinkers[i].id = i;
		data->thinkers[i].last_meal = get_time();
		data->thinkers[i].full = false;
		
	}
		error_exit("Malloc failed.");
	if (parse_input(data, argv) == FAILURE)
		error_exit("Invalid input.");
	

}

