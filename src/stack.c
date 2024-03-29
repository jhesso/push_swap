/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:18:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/14 18:58:14 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	stack_build()
*	builds stack a from the given arguments
*	returns the stack if everything went smoothly,
*	exits the program if something fails
*/
t_stack	*stack_build(char **input)
{
	t_stack	*stack_a;
	long	value;

	stack_a = NULL;
	while (*input)
	{
		value = ft_atoi(*input);
		if ((value < 0 && *input[0] != '-') || (value > 0 && *input[0] == '-') \
			|| (value == 0 && *input[0] != '0') || (value == -1 && \
			*input[0] != '-'))
			error_print(&stack_a, NULL);
		if (value > INT_MAX || value < INT_MIN)
			error_print(&stack_a, NULL);
		stack_add_back(stack_node_new((int)value), &stack_a);
		input++;
	}
	return (stack_a);
}

/*	check_limits()
*	checks if the stack contains INT_MAX or INT_MIN
*	and assigns the index correctly on those
*/
static int	check_limits(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		flag;

	tmp = *stack;
	flag = 0;
	while (tmp)
	{
		if (tmp->value == INT_MIN)
			tmp->index = 0;
		else if (tmp->value == INT_MAX)
		{
			tmp->index = size - 1;
			flag = 1;
		}
		tmp = tmp->next;
	}
	return (flag);
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
	if (check_limits(&stack, stack_size))
		stack_size--;
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

/*	stack_free()
*	frees the given stack and all its nodes.
*/
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

/*	stack_is_sorted()
*	goes through the given stack and checks if its sorted properly
*	returns: 1 if sorted, 0 if not
*	Note to self:
*	because we're comparing stack->index to stack->next->index, at the last index,
*	we will always compare some index to NULL (obvious segfault)
*	this is why we need to limit this
*/
int	stack_is_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			return (1);
		if (stack->index != stack->next->index - 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}
