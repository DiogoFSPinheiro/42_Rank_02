/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:49:44 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:16:14 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*rotate_bag;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	rotate_bag = find_last_node(*stack);
	rotate_bag->prev->next = NULL;
	(*stack)->prev = rotate_bag;
	rotate_bag->prev = NULL;
	(rotate_bag)->next = *stack;
	(*stack) = rotate_bag;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	printf("rrr\n");
}
