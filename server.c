/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:58:31 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/31 18:45:43 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_message(int sig)
{
	static char	c = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
		c = c | 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c\n", c);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 1)
	{
		ft_printf("ERROR : Invalid number of arguments!\n");
		return (0);
	}
	pid = getpid();
	ft_printf("The server PID is %d\n", pid);
	signal(SIGUSR1, ft_print_message);
	signal(SIGUSR2, ft_print_message);
	while (1)
		pause();
}
