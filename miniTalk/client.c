/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:21:50 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/21 15:48:05 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	server_mail(int pid, char c)
{
	int			n;
	char		bit;

	n = 0;
	while (n < 8)
	{
		if (c & (1 << n))
			bit = 1;
		else
			bit = 0;
		send_bit(pid, bit, 1);
		n++;
	}
}

static	void	msg_size(int pid, int c)
{
	int			n;
	char		bit;

	n = 0;
	while (n < 32)
	{
		if (c & (1 << n))
			bit = 1;
		else
			bit = 0;
		send_bit(pid, bit, 1);
		n++;
	}
}

static void	client_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_println("Message successfully sent");
		exit (EXIT_SUCCESS);
	}
	else if (sig == SIGUSR2)
		ft_printf("*");
}

int	main(int argc, char **argv)
{
	unsigned int		pid;
	int					s;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_println("	You inputed the wrong format");
		ft_println("	The right format is ./client <PID number> <message>");
		ft_println("	Example: ./client 12456 \"how you doing\"");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	s = ft_strlen(argv[2]);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = client_handler;
	sa.sa_flags = SA_RESTART;
	set_up_sigaction(&sa);
	msg_size(pid, s);
	while (*argv[2])
		server_mail(pid, *argv[2]++);
	server_mail(pid, '\0');
	return (EXIT_SUCCESS);
}
