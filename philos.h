/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:51 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/09 23:14:59 by seckhard         ###   ########.fr       */
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
	size_t				id;
	long int			philo_nbr;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				meals;
	size_t				last_meal;
	bool				full;
	int					*dead;
	pthread_t			philos;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*eaten_lock;
}				t_table;

typedef struct s_data
{
	t_table				*thinkers;
	int					dead;
	int					has_eaten;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		eaten_lock;
}				t_data;

// Utils
int		create_mutex(t_data *data);
void	input_check(char **argv);
size_t	get_time(void);

// Error
void	error_exit(const char *error);
void	destroy_mutex(pthread_mutex_t *mutex, int i);
void	destroy_philos(t_data *data);
void	destroy_forks(t_table *table, int i);

// Init
int		init_philos(t_data *data, char **argv);
int		parse_input(t_table *table, char **argv);

// Dinner party
int		dinner_party(t_data *data); // TO DO

// Dinner police
int 	dinner_police(t_table *thinker); // TO DO

#endif