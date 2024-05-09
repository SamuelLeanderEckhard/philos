/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:00:10 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 22:01:12 by seckhard         ###   ########.fr       */
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
int	create_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (error("mutex print_lock failed"));
	if (pthread_mutex_init(&data->eaten_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->eaten_lock);
		return (error("mutex eaten_lock failed"));
	}
	return (OK);
}

size_t	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
