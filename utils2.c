/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seckhard <seckhard@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:21:41 by seckhard          #+#    #+#             */
/*   Updated: 2024/05/11 21:23:58 by seckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	sleep_improved(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

// sleeping function