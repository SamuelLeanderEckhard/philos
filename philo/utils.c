/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:00:10 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 16:29:02 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	is_valid(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 0 || argv[i][j] > 9)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (OK);
}

void	input_check(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		while (argv[i] == ' ' || (argv[i] >= 9 && argv[i] <= 13))
			i++;
		if (is_valid(argv) == FAILURE)
			error_exit("needs to be positive numeric.");
		i++;
	}
}
void	create_mutex(t_table *table)
{
	int i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nbr);
	if (!table->forks)
		error_exit("Malloc failed");
	while (i < table->philo_nbr)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}