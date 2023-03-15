/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:42:26 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/15 17:20:09 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	push_swap()
*	this is the "main" for the actual solving part.
*	takes two stacks (stack_a and stack_b) and sorts the stacks in a way that
*	stack_a contains all values in ascending order in the end
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_is_sorted(*stack_a))
	{
		stack_free(stack_a);
		return ;
	}
	if (stack_size == 2)
		op_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3)
		sort(stack_a, stack_b);
}
