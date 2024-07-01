/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:12:18 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/21 15:47:50 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_s;

static void	free_mem_reset(char *msg)
{
	free(msg);
	g_s = 0;
}

static void	add_to_str(char **str, char c, siginfo_t *info)
{
	static int	i;

	(*str)[i++] = c;
	if (c == '\0')
	{
		ft_println("%s", *str);
		free_mem_reset(*str);
		kill(info->si_pid, SIGUSR1);
		i = 0;
	}
}

static void	reset_counters(int *c, int *n)
{
	*n = 0;
	*c = 0;
}

static void	handle_sig(int sig, siginfo_t *info, void *context)
{
	static int		c;
	static int		n;
	static char		*msg;

	(void)context;
	usleep(750);
	if (sig == SIGUSR1)
		c |= (1 << n);
	n++;
	if (n == 8 && g_s == 1)
	{
		add_to_str(&msg, c, info);
		reset_counters(&c, &n);
	}
	else if (n == 32 && g_s == 0)
	{
		msg = ft_calloc((c + 1), sizeof(char));
		if (!msg)
			ft_perror_exit("Calloc Error");
		reset_counters(&c, &n);
		g_s = 1;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	g_s = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	set_up_sigaction(&sa);
	print_pid();
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
