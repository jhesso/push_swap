/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:18:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/02 17:38:02 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_build(char **argv)
{
	t_stack	*stack_a;
	long	value;
	int		i;

	i = 1;
	stack_a = NULL;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			error_print(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_node_new((int)value);
		else
			stack_add_back(stack_node_new((int)value), &stack_a);
		i++;
	}
	return (stack_a);
}

/*	stack_index()
*	assign an index to each node on a stack
*	indexes are assigned from highest (stack_size) to lowest (0)
*/
void	stack_index(t_stack *stack, int stack_size)
{
	t_stack	*stack_ptr;
	int		roof;
	int		floor;

	roof = INT_MAX;
	while (stack_size > 0)
	{
		floor = INT_MIN;
		stack_ptr = stack;
		while (stack_ptr)
		{
			if (stack_ptr->value > floor && stack_ptr->value < roof)
			{
				floor = stack_ptr->value;
				stack_ptr->index = stack_size - 1;
			}
			stack_ptr = stack_ptr->next;
		}
		roof = floor;
		stack_size--;
	}
}

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
