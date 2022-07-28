/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:22:26 by clora-ro          #+#    #+#             */
/*   Updated: 2022/07/28 12:11:55 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct s_philo
{
	int	id;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	long	start_time;

	struct timeval time;
	pthread_t thread_philo;
	pthread_mutex_t	lfork;
	pthread_mutex_t	*rfork;
	// struct *s_data;
}	t_philo;

typedef struct s_data
{
	int	nb;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	t_philo *philo;
}	t_data;


/*									main.c									*/

void	ft_destroy(t_data *data);
void	ft_philosophers(char **av, t_data *data);


/*									init.c									*/

void	ft_init_philo(t_data *data);
void	ft_init_fork(t_data *data);
void 	ft_init_threads(t_data *data);
// static void*	fn_philo(void *p_data);

#endif
