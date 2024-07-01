/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:42:34 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/21 16:12:18 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

void	set_up_sigaction(struct sigaction *sa);
int		ft_perror_exit(char *str);
void	send_bit(pid_t pid, char bit, char response);
void	print_pid(void);

#endif
