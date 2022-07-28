/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:20:26 by clora-ro          #+#    #+#             */
/*   Updated: 2022/07/28 12:11:58 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		pthread_join(data->philo[i].thread_philo, NULL);
		i++;
	}
}

void	ft_philosophers(char **av, t_data *data)
{
	int	number_of_philosophers;
	
	number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->philo = malloc(sizeof(t_philo) * number_of_philosophers);
	data->nb = number_of_philosophers;
	ft_init_philo(data);
	// ft_init_fork(data);
	// dprintf(1, "\nphilo : %d / %d / %d / %d\n", number_of_philosophers, time_to_die, time_to_eat, time_to_sleep);
	printf("Philosophers threads created nb = %d\n\n", data->nb);
	ft_init_threads(data);
	ft_destroy(data);
}

int	main(int ac, char **av)
{
	t_data *data;
	
	data = NULL;
	data = malloc(sizeof(t_data));
	if (ac == 5)
	{
		ft_philosophers(av, data);
	}
	write(1, "\n", 1);
	return(0);
}
