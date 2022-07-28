/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:43:56 by clora-ro          #+#    #+#             */
/*   Updated: 2022/07/28 14:13:39 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
long	get_time(void)
{
	struct timeval	time;
	long			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000;
	milliseconds += time.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep()
{
	int	tmp;
	int	i;

	i = 0;
	tmp = get_time();
	while (i < 5)
	{
	}
	
}

static void*	fn_philo(void *p_philo)
{
	t_philo	*philo = (t_philo *) p_philo;
	philo->start_time = get_time();

	// printf("Seconds : %ld\nMicro seconds : %d\n", philo->time.tv_sec, philo->time.tv_usec);

	if (philo->id % 2 != 0)
	{
		printf("%ld %d is thinking\n", get_time() - philo->start_time, philo->id);
		usleep(philo->time_to_eat / 2);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->lfork);
		printf("%ld %d has taken a fork\n", get_time() - philo->start_time, philo->id);

		pthread_mutex_lock(philo->rfork);
		printf("%ld %d has taken a fork\n", get_time() - philo->start_time, philo->id);
		printf("%ld %d is eating\n", get_time() - philo->start_time, philo->id);
		usleep(philo->time_to_eat * 1000);
		// sleep(1);
		pthread_mutex_unlock(&philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		printf("%ld %d is sleeping\n", get_time() - philo->start_time, philo->id);
		usleep(philo->time_to_sleep * 1000);
		printf("%ld %d is thinking\n", get_time() - philo->start_time, philo->id);
	}
	return (NULL);
}

void	ft_init_threads(t_data *data)
{
	int ret = 0;
	int i = 0;

	while (i < data->nb)
	{
		ret = pthread_create(&data->philo[i].thread_philo, NULL, fn_philo, (void *) &data->philo[i]);
		i++;

	}
}
