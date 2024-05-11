/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:41 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 20:48:47 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_table	thinkers[200];

	data.thinkers = thinkers;
	if (argc != 5 && argc != 6)
		return (error_exit("Wrong input, type: ./philo 5 800 200 200 (optional: 3)"), FAILURE);
	if (input_check(argv) == FAILURE)
		return (FAILURE);
	if (create_mutex(&data) == FAILURE)
		return (FAILURE);
	if (init_philos(&data, argv) == FAILURE)
		return (FAILURE);
	if (dinner_party(&data) == FAILURE)
		return (FAILURE);
	destroy_forks(thinkers, data.thinkers->philo_nbr);
	return (OK);
}
