/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:00:10 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 21:08:01 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

static int	is_valid(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (OK);
}

int	input_check(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13))
			j++;
		if (is_valid(argv) == FAILURE)
			return (error_exit("needs to be positive numeric."), FAILURE);
		i++;
	}
	return (OK);
}

int	create_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (error_exit("mutex print_lock failed"), FAILURE);
	if (pthread_mutex_init(&data->eaten_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->eaten_lock);
		return (error_exit("mutex eaten_lock failed"), FAILURE);
	}
	return (OK);
}

size_t	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

size_t	ft_atoi(char *str)
{
	size_t	x;
	int		sign;

	x = 0;
	sign = 1;
	while (*str == ' ' || *str == '\v' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			x = x * 10 + *str - '0';
		else
			break ;
		if ((x > 2147483647 && sign == 1) || (sign == -1))
			return (9876543210);
		str++;
	}
	return (sign * x);
}
