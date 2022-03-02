/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 09:57:43 by samoreno          #+#    #+#             */
/*   Updated: 2022/02/02 10:09:31 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send(char *str, int pid);
static int	ft_errors(int argc, char **argv);
static int	ft_atoi(const char *str);

int	main(int argc, char **argv)
{
	int				pid;
	unsigned long	iter_len;
	int				iter_ch;

	if (ft_errors(argc, argv) == 0)
	{
		pid = ft_atoi(argv[1]);
		iter_ch = 0;
		iter_len = 0;
		while (iter_len < ft_strlen(argv[2]))
		{
			kill(pid, SIGUSR1);
			usleep(100);
			iter_len++;
		}
		kill(pid, SIGUSR2);
		usleep(100);
		ft_send(argv[2], pid);
	}
	usleep(200);
	return (0);
}

static int	ft_errors(int argc, char **argv)
{
	int	iter;

	iter = 0;
	if (argc != 3)
	{
		if (argc == 1)
			ft_printf("Error: PID and string needed\n");
		if (argc == 2)
			ft_printf("Error: string needed\n");
		if (argc > 3)
			ft_printf("Error: Too many arguments\n");
		return (1);
	}
	while (argv[1][iter])
	{
		if (argv[1][iter] < '0' || argv[1][iter] > '9')
		{
			ft_printf("Error: PID must be strictly numerical\n");
			return (1);
		}
		iter++;
	}
	return (0);
}

static void	ft_send(char *str, int pid)
{
	int	iter_bit;
	int	iter_ch;

	iter_ch = 0;
	while (str[iter_ch])
	{
		iter_bit = 0;
		while (iter_bit < 8)
		{
			if (str[iter_ch] & (1 << iter_bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			iter_bit++;
			usleep(100);
		}
		iter_ch++;
	}
	iter_bit = 0;
	while (iter_bit < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		iter_bit++;
	}
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	negs;
	int	return_number;

	i = 0;
	negs = 0;
	return_number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negs++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_number = (return_number * 10) + (str[i] - '0');
		i++;
	}
	if (negs)
		return_number *= -1;
	return (return_number);
}
