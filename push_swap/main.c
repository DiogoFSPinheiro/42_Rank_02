/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:40:36 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:54:17 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*get_first_node(t_stack_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	bool			i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]) || space_checker(argv[1]))
		return (write(2, "Error\n", 6));
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 1;
	}
	if (i)
		stack_a_init(&a, argv, 2 == argc);
	else
		stack_a_init(&a, argv + 1, 2 == argc);
	if (!sorted(a))
		push_swap(a, b);
	a = get_first_node(a);
	free_stacks(&a);
}
