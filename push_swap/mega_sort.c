/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mega_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:48:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:20:31 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mega_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	if (ft_stacklen(*a) > 3 && !sorted(*a))
		pb(a, b);
	if (ft_stacklen(*a) > 3 && !sorted(*a))
		pb(a, b);
	while (ft_stacklen(*a) > 3)
	{
		get_nodes_ready_a(*a, *b);
		move_nodes_a(a, b);
	}
	orderthree(a);
	while (*b)
	{
		get_nodes_ready_b(*a, *b);
		move_nodes_b(a, b);
	}
	get_median_position(*a);
	smallest = find_min(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}

void	get_cheapest(t_stack_node *stack)
{
	long			best_price;
	t_stack_node	*best_node;

	best_node = NULL;
	if (!stack)
		return ;
	best_price = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < best_price)
		{
			best_price = stack->push_cost;
			best_node = stack;
		}
		stack = stack->next;
	}
	best_node->cheapest = true;
}

void	get_median_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (NULL == stack)
		return ;
	center = ft_stacklen(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= center)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
