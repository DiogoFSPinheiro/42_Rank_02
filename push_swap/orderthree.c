/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderthree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:18:35 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:15:51 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*top;
	int				max;

	top = stack;
	max = top->nbr;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			top = stack;
		}
		stack = stack->next;
	}
	return (top);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*bot;
	int				min;

	bot = stack;
	min = bot->nbr;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			bot = stack;
		}
		stack = stack->next;
	}
	return (bot);
}

void	orderthree(t_stack_node **stack)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*stack);
	if (biggest_node == *stack)
		ra(stack);
	else if (biggest_node == (*stack)->next)
		rra(stack);
	if ((*stack)->next->nbr < (*stack)->nbr)
		sa(stack);
}
