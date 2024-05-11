/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:41 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 20:32:59 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_table	thinkers[200];

	data.thinkers = thinkers;
	if (argc != 5 && argc != 6)
		error_exit("Wrong input, type: ./philo 5 800 200 200 (optional: 3)");
	else
	{
		input_check(argv);
		create_mutex(&data);
		init_philos(&data, argv);
		dinner_party(&data);
	}
	destroy_forks(thinkers, data.thinkers->philo_nbr);
}
