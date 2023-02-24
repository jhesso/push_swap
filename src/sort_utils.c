/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:13:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/24 17:28:36 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	stack_find_highest_index()
*	finds the node with the highest index on a stack
*	returns the highest index found
*/
int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/*	get_pos()
*	goes through given stack and assigns a position to each node
*	this is used to calculate the cost of moving a certain number to a certain
*	position
*/
void	get_pos(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

/*	target()
*	picks the best target position in stack a for the given index of an element
*	 in stack b. first checks if the index of the b element can be placed
*	somewhere in between elements in stack a, by checking wether there is an
*	element in  stack a with a bigger index, if not, it finds the element
*	with the smallest index in a and assigns that as the target position
*/
static int	target(t_stack **a, int index_b, int index_target, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > index_b && temp_a->index < index_target)
		{
			target_pos = temp_a->pos;
			index_target = temp_a->index;
		}
		temp_a = temp_a->next;
	}
	if (index_target != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < index_target)
		{
			index_target = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

/*	get_target_pos()
*	Assign a target position in stack a to each element of stack a
*	the target position is the spot the element in b needs to get to in order to
*	be sorted correctly. This positiion will be used to calculate the cost of
*	moving each element to its target position in stack a.
*/
void	get_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *b;
	get_pos(a);
	get_pos(b);
	target_pos = 0;
	while (temp_b)
	{
		target_pos = target(a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_pos = target_pos;
		temp_b = temp_b->next;
	}
}
