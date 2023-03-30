/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:05:45 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 04:11:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <fcntl.h>
# include "../../../libft/includes/libft.h"

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

/* checker.c */
void	checker(t_stack *a, t_stack *b, char **operations);

/* operations.c */
char	**get_operations(void);

/* operations_validate.c */
int		operations_validate(char **operations);

/* utils.c */
void	checker_error(char **operations, t_stack **a, t_stack **b);
char	**allocate_str(char **argv, int argc);
void	free_input(char **input);

/* debug.c */
void	debug_stack_print_values(t_stack *stack);
void	debug_node_print_content(t_stack *node);
void	debug_input_print(char **input);

/* input_validate.c */
char	**input_validate(char **argv, int argc);

/* stack.c*/
t_stack	*stack_build(char **input);
void	stack_index(t_stack *stack, int stack_size);
void	stack_free(t_stack **stack);
int		stack_is_sorted(t_stack *stack);

/* stack_utils.c */
t_stack	*stack_node_new(int value);
t_stack	*stack_get_tail(t_stack *stack);
void	stack_add_back(t_stack *node, t_stack **stack);
int		stack_get_size(t_stack *stack);
t_stack	*stack_node_del_top(t_stack *stack);

/* operations */
void	op_sa(t_stack **a);
void	op_sb(t_stack **b);
void	op_ss(t_stack **a, t_stack **b);
void	op_pa(t_stack **stack_a, t_stack **stack_b);
void	op_pb(t_stack **stack_b, t_stack **stack_a);
void	op_ra(t_stack **stack_a);
void	op_rb(t_stack **stack_b);
void	op_rr(t_stack **stack_a, t_stack **stack_b);
void	op_rra(t_stack **stack_a);
void	op_rrb(t_stack **stack_b);
void	op_rrr(t_stack **stack_a, t_stack **stack_b);

#endif
