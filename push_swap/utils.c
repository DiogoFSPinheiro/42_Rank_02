/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:23:55 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/07 13:28:23 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacklen(t_stack_node *stack)
{
	int	c;

	if (!stack)
		return (0);
	c = 0;
	while (stack)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

bool	space_checker(char *argv)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (argv[c])
	{
		if (argv[c] != ' ')
			i++;
		c++;
	}
	if (i > 0)
		return (0);
	else
		return (1);
}

bool	sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
