/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:03:32 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/31 18:27:49 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	ft_atoi(char *pid)
{
	int		i;
	pid_t	res;

	i = 0;
	res = 0;
	while (pid[i])
	{
		res = res * 10 + pid[i] - 48;
		i++;
	}
	return (res);
}

int	ft_check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!(pid[i] >= 48 && pid[i] <= 57))
		{
			ft_printf("ERROR : Invalid PID!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_send_message(char *message, pid_t pid)
{
	char	c;
	int		i;

	i = 0;
	c = message[i];
	if (c >> i & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	i++;
	c = '\0';
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("ERROR : Invalid number of arguments!\n");
		return (0);
	}
	if (ft_check_pid(argv[1]) == 1)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_send_message(argv[2], pid);
}
