/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:19:52 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/24 17:40:49 by jhesso           ###   ########.fr       */
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

/*	sort()
*	sort the stacks by implementing a version of quicksort
*	we choose the first index as a "pivot" and then we iterate through the whole
*	list, pushing every node with an index lower than the pivot to stack b
*	then we recursively sort the stacks using the same method until both stacks
*	are sorted. then we simply push everything from stack b onto a and our
*	stack a is properly sorted.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->next->next->next)
	{
		op_pb(stack_b, stack_a);
		*stack_a = (*stack_a)->next;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
	}
}
