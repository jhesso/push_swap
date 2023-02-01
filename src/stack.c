/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:18:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/01 19:53:11 by jhesso           ###   ########.fr       */
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
			;// ! Print max/min int errror
		if (i == 1)
			stack_new((int)value);
		else
			stack_add_back(stack_new((int)value), &stack_a);
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
	t_stack	*highest;
	int		value;

	stack_ptr = stack;
	value = INT_MIN;
	highest = NULL;
	while (--stack_size > 0)
	{
		if (stack_ptr->value == INT_MIN && stack_ptr->index == -1)
			stack_ptr->index = 0;
		if (stack_ptr->value > value && stack_ptr->index == -1)
		{
			value = stack_ptr->value;
			highest = stack_ptr;
			stack_ptr = stack;
		}
		else
			stack_ptr = stack_ptr->next;
		if (highest != NULL)
			highest->index = stack_size;
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
