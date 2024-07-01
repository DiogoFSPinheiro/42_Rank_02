/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:26:13 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 16:16:15 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node	*a, t_stack_node *b)
{
	if (ft_stacklen(a) == 2)
		ra(&a);
	else if (ft_stacklen(a) == 3)
		orderthree(&a);
	else
		mega_sort(&a, &b);
}

void	append_node(t_stack_node **a, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!a)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_a_init(t_stack_node **a, char **args, bool arg_2)
{
	int	c;

	c = 0;
	if (verify(args))
	{
		while (args[c])
		{
			append_node(a, ft_atol(args[c]));
			c++;
		}
	}
	else
		free_errors(a, args, arg_2);
	if (arg_2)
		free_args(args);
}
