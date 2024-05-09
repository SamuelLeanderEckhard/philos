/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:41 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 18:08:11 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 || argc != 6)
		error_exit("Wrong input, type: ./philo 5 800 200 200");
	else
	{
		input_check(argv);
		init_philos(table, argv);
		dinner_party(table, argv);
	}
}
