/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:26:29 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:18:45 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	i;
	long	b;
	long	c;

	i = 0;
	b = 1;
	c = 0;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		++i;
	}
	return (c * b);
}

static int	error_syntax(char *nbr)
{
	if (!(*nbr == '+' || *nbr == '-' || (*nbr >= '0' && *nbr <= '9')))
		return (1);
	if ((*nbr == '+' || *nbr == '-') && !(nbr[1] >= '0' && nbr[1] <= '9'))
		return (1);
	while (*++nbr)
	{
		if (!(*nbr >= '0' && *nbr <= '9'))
			return (1);
	}
	return (0);
}

int	verify(char **numbers)
{
	int	c;
	int	i;

	c = 0;
	while (numbers[c])
	{
		i = c + 1;
		if (error_syntax(numbers[c]) || (ft_atol(numbers[c]) > INT_MAX
				|| ft_atol(numbers[c]) < INT_MIN))
			return (0);
		while (numbers[i])
		{
			if (ft_atol(numbers[c]) == ft_atol(numbers[i]))
				return (0);
			i++;
		}
		c++;
	}
	return (1);
}

void	print_stack(t_stack_node *a, bool y, bool index)
{
	t_stack_node	*temp;

	temp = a;
	while (temp)
	{
		if (y == true && index == true)
			ft_printf("%d -> target: %d -> index: %d -> cost: %d", temp->nbr,
				temp->target_node->nbr, temp->index);
		else if (index == true)
			ft_printf("%d -> index: %d\n", temp->nbr, temp->index);
		else if (y == true)
			ft_printf("%d -> %d\n", temp->nbr, temp->target_node->nbr);
		else
			ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
}
