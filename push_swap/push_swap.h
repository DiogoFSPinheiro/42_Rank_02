/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:04:43 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/13 15:17:59 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//Stack inits
void			stack_a_init(t_stack_node **a, char **args, bool arg_2);
bool			space_checker(char *argv);
bool			sorted(t_stack_node *stack);
//Nodes inits
void			push_swap(t_stack_node	*a, t_stack_node *b);

//Stack utils
t_stack_node	*find_last_node(t_stack_node *stack);
long			ft_atol(const char *str);
int				verify(char **numbers);
int				ft_stacklen(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			print_stack(t_stack_node *a, bool y, bool index);

//stack a only
void			get_nodes_ready_a(t_stack_node *a, t_stack_node *b);
void			get_target_node_a(t_stack_node *a, t_stack_node *b);
void			get_cost_a(t_stack_node *a, t_stack_node *b);
void			move_nodes_a(t_stack_node **a, t_stack_node **b);

//stack b only
void			get_nodes_ready_b(t_stack_node *a, t_stack_node *b);
void			get_target_node_b(t_stack_node *a, t_stack_node *b);
void			get_cost_b(t_stack_node *a, t_stack_node *b);
void			move_nodes_b(t_stack_node **a, t_stack_node **b);

//stack both
void			get_median_position(t_stack_node *stack);
void			get_cheapest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);

//frees
void			free_errors(t_stack_node **a, char **argv, bool argc_2);
void			free_args(char **numbers);
void			free_stacks(t_stack_node **stack);

//Commands
//push
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
//swap
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
//rotate
void			ra(t_stack_node **stack);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
//reverse rotate
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//algoritms
void			orderthree(t_stack_node **stack);
void			mega_sort(t_stack_node **a, t_stack_node **b);

#endif
