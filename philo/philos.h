/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:51 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/08 21:17:08 by seckhard         ###   ########.fr       */
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

typedef struct	s_philos
{
	int			id;
	double		meals;
	bool		full;
	double		last_meal;
	pthread_t	number_of_philosophers;
	t_forks		*first_fork;
	t_forks		*second_fork;
	t_table		*table;
}			t_philos;

typedef struct s_table
{	
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		start;
	bool		end;
	long		limit_meals;
	t_forks		*forks;
	t_philos	*philos;
}			t_table;


void    error_exit(const char *error);

void	parse_input(t_table *table, char **argv);

void	*safe_malloc(size_t size);
void	safe_mutex_handle(t_philos *mutex, t_opcode opcode);


#endif
