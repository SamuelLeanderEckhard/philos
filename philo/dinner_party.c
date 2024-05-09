/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:26:27 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 16:10:32 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	dinner_party(t_table *table)
{
	int i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_create(&table->philos[i].thread, NULL, &philo_life, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
