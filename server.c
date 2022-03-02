/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:07:56 by samoreno          #+#    #+#             */
/*   Updated: 2022/02/02 09:57:52 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_signal(int signal);
static void	ft_allocate(int signal);

t_mini	g_info;

int	main(void)
{
	int				pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, ft_signal);
	signal(SIGUSR2, ft_signal);
	while (1)
		sleep(1);
	return (0);
}

static void	ft_signal(int signal)
{
	if (g_info.len_flag == 0)
		ft_allocate(signal);
	else if (g_info.iter < 8)
	{
		if (signal == SIGUSR1)
			g_info.ch = (g_info.ch | (1 << g_info.iter));
		g_info.iter++;
	}
	if (g_info.iter == 8)
	{
		g_info.str[g_info.iter_str] = g_info.ch;
		g_info.iter_str++;
		if (g_info.ch == 0)
		{
			ft_printf("%s", g_info.str);
			free(g_info.str);
			g_info.len_flag = 0;
			g_info.iter_str = 0;
		}
		g_info.iter = 0;
		g_info.ch = 0;
	}
}

static void	ft_allocate(int signal)
{
	if (signal == SIGUSR1)
		g_info.len++;
	else
	{
		g_info.str = malloc(sizeof(char) * (g_info.len + 1));
		if (!g_info.str)
		{
			ft_printf("Error: memory allocation error\n");
			exit(1);
		}
		g_info.len = 0;
		g_info.len_flag++;
	}
}
