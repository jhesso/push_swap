/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:39:50 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/03 10:52:22 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	debug_stack_print_values(t_stack *stack)
{
	int	nb;

	nb = 0;
	while (stack != NULL)
	{
		ft_printf("node: %d value: %d index: %d\n", nb, stack->value, stack->index);
		stack = stack->next;
		nb++;
	}
}

void	debug_node_print_content(t_stack *node)
{
	ft_printf("node value: %d\n", node->value);
	ft_printf("node index: %d\n", node->index);
	ft_printf("node pos: %d\n", node->pos);
	ft_printf("node target_pos: %d\n", node->target_pos);
	ft_printf("node cost_a: %d\n", node->cost_a);
	ft_printf("node cost_b: %d\n", node->cost_b);
	ft_printf("node next: %p\n", node->next);
}

void	debug_input_print(char **input)
{
	while (*input)
	{
		ft_printf("%s\n", *input);
		input++;
	}
}
