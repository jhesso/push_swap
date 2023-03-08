/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:19:52 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/08 17:17:10 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	sort_three()
*	sort a stack of 3 numbers in 2 or fewer moves
*/
void	sort_three(t_stack **stack)
{
	int	highest;

	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		op_ra(stack);
	else if ((*stack)->next->index == highest)
		op_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		op_sa(stack);
}

/*	stack_get_lowest_index_pos()
*	find the node with the lowest index from the given stack
*	returns the position of the node with the lowest index
*/
static int	stack_get_lowest_index_pos(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;

	temp = *stack;
	lowest_index = find_lowest_index(temp);
	get_pos(stack);
	lowest_pos = temp->pos;
	while (temp)
	{
		if (temp->index == lowest_index)
			lowest_pos = temp->pos;
		temp = temp->next;
	}
	return (lowest_pos);
}

/*	stack_shift()
*	after the bulk of the stack is sorted, shifts stack a until lowest
*	value is at the top. If it is in the bottomhalf, reverse rotate, else rotate
*/
static void	stack_shift(t_stack **a)
{
	int	lowest;
	int	stack_size;

	stack_size = stack_get_size(*a);
	lowest = stack_get_lowest_index_pos(a);
	if (lowest > stack_size / 2)
	{
		while (lowest < stack_size)
		{
			op_rra(a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			op_ra(a);
			lowest--;
		}
	}
}

/*	push_all_but_three()
*	pushes all elements of stack a into b, except for the last three.
*	push the smaller values first, and then the larger values to help
*	with sorting efficiency
*/
static void	push_all_but_three(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = stack_get_size(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			op_pb(b, a);
			pushed++;
		}
		else
			op_ra(a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		op_pb(b, a);
		pushed++;
	}
}

/*	sort()
*	sorts stack a in ascending order by utilizing the sort_three function
*	and calculating the most cost effective way to sort the rest.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!stack_is_sorted(*stack_a))
		stack_shift(stack_a);
}
