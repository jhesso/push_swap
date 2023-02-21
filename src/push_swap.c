/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:42:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/21 20:43:01 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	stack_find_highest_index()
*	finds the node with the highest index on a stack
*	returns the highest index found
*/
static int	stack_find_highest_index(t_stack *stack)
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

/*	tiny_sort()
*	Sorts a stack of 3 numbers in 2 or fewer moves.
*	Utilizes the indexing we added on the stack rather than the actual values
*/
void	sort_small(t_stack **stack)
{
	int	highest;

	highest = stack_find_highest_index(*stack);
	ft_printf("highest index is: %d\n", highest);
	if ((*stack)->index == highest)
	{
		ft_printf("calling op_ra()\n");
		op_ra(stack);
		ft_printf("ra done\n");
	}
	else if ((*stack)->next->index == highest)
	{
		ft_printf("calling op_rra()\n");
		op_rra(stack);
	}
	ft_printf ("test\n");
	//!	something weird happens to the stack and it points to null or something, meaning that the
	//!	program segfaults here :(
	ft_printf("stack->index: %d\n", (*stack)->index);\
	if ((*stack)->index > (*stack)->next->index)
	{
		ft_printf("calling op_sa()\n");
		op_sa(stack);
	}
	ft_printf ("test\n");
}

/*	push_swap()
*	this is the "main" for the actual solving part.
*	takes two stacks (stack_a and stack_b) and sorts the stacks in a way that
*	stack_a contains all values in ascending order in the end
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	ft_printf("%d\n", (*stack_a)->index);
	if (stack_size == 2)
		op_sa(stack_a);
	else if (stack_size == 3)
	{
		ft_printf("calling sort_small()\n");
		sort_small(stack_a);
	}
	else if (stack_size > 3)
		sort(stack_a, stack_b);
}
