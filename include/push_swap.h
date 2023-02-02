/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:50 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/01 18:12:17 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* validation */
int		input_validate(char **argv, int argc);

/* stack initialization */
t_stack	*stack_build(char **argv);
void	stack_index(t_stack *stack, int	stack_size);
void	stack_free(t_stack **stack);

/* stack utils */
t_stack	*stack_node_new(int value);
t_stack	*stack_get_tail(t_stack *stack);
int		stack_get_size(t_stack *stack);
void	stack_add_back(t_stack *node, t_stack **stack);

/* debugging functions */
void	stack_print_values(t_stack *stack);

/* general utility functions */
void	error_print(t_stack **stack_a, t_stack **stack_b);

#endif
