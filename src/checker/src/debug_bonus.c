/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:39:50 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 03:20:12 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	debug_stack_print_values(t_stack *stack)
{
	while (stack != NULL)
	{
		debug_node_print_content(stack);
		stack = stack->next;
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
		ft_printf("%s", *input);
		input++;
	}
	ft_printf("----------------\n");
}

void	write_to_file(char **operations)
{
	int	i;
	int	fd;

	i = 0;
	fd = open("test", O_WRONLY | O_APPEND | O_CREAT);
	if (fd == -1)
		exit(-1);
	while (operations[i])
	{
		ft_putstr_fd(operations[i], fd);
		i++;
	}
}
