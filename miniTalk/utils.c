/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:51:50 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/21 14:38:16 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	set_up_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
		ft_perror_exit("Error setting up SIGUSR1");
	if (sigaction(SIGUSR2, sa, NULL) < 0)
		ft_perror_exit("Error setting up SIGUSR2");
}

int	ft_perror_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(STDERR_FILENO, str, len);
	exit(EXIT_FAILURE);
}

void	send_bit(pid_t pid, char bit, char response)
{
	if (bit == 1)
	{
		if (kill(pid, SIGUSR1) < 0)
			ft_perror_exit("Error sending SIGUSR1");
	}
	else if (bit == 0)
	{
		if (kill(pid, SIGUSR2) < 0)
			ft_perror_exit("Error sending SIGUSR2");
	}
	if (response != 0)
		pause();
}

void	print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\nServer PID: [%d]\n\n\n", pid);
	ft_printf("############# Printing Area #############\n\n");
}
