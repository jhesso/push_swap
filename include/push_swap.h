/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:50 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/14 19:02:23 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* validation */
char	**input_validate(char **argv, int argc);

/* stack initialization */
t_stack	*stack_build(char **argv);
void	stack_index(t_stack *stack, int stack_size);
void	stack_free(t_stack **stack);
int		stack_is_sorted(t_stack *stack);

/* stack utils */
t_stack	*stack_node_new(int value);
int		stack_get_size(t_stack *stack);
t_stack	*stack_get_tail(t_stack *stack);
t_stack	*stack_node_del_top(t_stack *stack);
void	stack_add_back(t_stack *node, t_stack **stack);

/* sorting */
void	sort_three(t_stack **stack);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

/* sorting utilities */
void	get_pos(t_stack **stack);
int		find_highest_index(t_stack *stack);
void	get_target_pos(t_stack **a, t_stack **b);
int		find_lowest_index(t_stack *stack);

/* cost */
void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* swap */
void	op_swap(t_stack *stack);
void	op_sa(t_stack **stack_a);
void	op_sb(t_stack **stack_b);
void	op_ss(t_stack **stack_a, t_stack **stack_b);

/* push */
void	op_pa(t_stack **stack_a, t_stack **stack_b);
void	op_pb(t_stack **stack_b, t_stack **stack_a);

/* rotate */
void	op_ra(t_stack **stack_a);
void	op_rb(t_stack **stack_b);
void	op_rr(t_stack **stack_a, t_stack **stack_b);

/* reverse rotate */
void	op_rra(t_stack **stack_a);
void	op_rrb(t_stack **stack_b);
void	op_rrr(t_stack **stack_a, t_stack **stack_b);

/* general utility functions */
void	error_print(t_stack **stack_a, t_stack **stack_b);
char	**allocate_str(char**argv, int argc);

/* debugging functions */
void	debug_stack_print_values(t_stack *stack);
void	debug_node_print_content(t_stack *node);
void	debug_input_print(char **input);
void	free_input(char **input);

#endif
