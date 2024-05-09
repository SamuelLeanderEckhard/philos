/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:51 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 17:51:10 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# define OK 0
# define FAILURE 1

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>
#include <errno.h>
#include <sys/time.h>
#include <limits.h>

typedef struct	s_table
{
	size_t					id;
	size_t					philo_nbr;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	size_t					meals;
	size_t					last_meal;
	bool				full;
	pthread_t			philos;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}				t_table;

typedef struct s_data
{
	t_table		*thinkers;
	int			dead;
	int			has_eaten;
}			t_data;


void	input_check(char **argv);


#endif
