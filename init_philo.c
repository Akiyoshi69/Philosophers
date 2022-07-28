/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:16:40 by clora-ro          #+#    #+#             */
/*   Updated: 2022/07/27 15:44:40 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_init_fork(t_data *data)
{
	int	i;

	i = data->nb;
	pthread_mutex_init(&data->philo[0].lfork, NULL);
	while (i-- > 0)
	{
		pthread_mutex_init(&data->philo[i].lfork, NULL);
		dprintf(2, "rfork %d = lfork %d\n", i, (i + 1 ) % data->nb);
		data->philo[i].rfork = &data->philo[(i + 1) % data->nb].lfork;
	}
	if (data->nb == 1)
		data->philo[0].rfork = NULL;
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		data->philo[i].id = i + 1;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		i++;
	}
	ft_init_fork(data);
}
