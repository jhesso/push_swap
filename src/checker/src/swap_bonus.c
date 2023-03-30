/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:49:01 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 04:17:42 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

/*	op_swap()
*	swap the first two nodes of given stack
*/
void	op_swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

/*	op_sa()
*	calls op_swap() on stack_a and prints sa on stdout
*/
void	op_sa(t_stack **stack_a)
{
	op_swap(*stack_a);
}

/*	op_sb()
*	calls op_swap() on stack_b and prints sb on stdout
*/
void	op_sb(t_stack **stack_b)
{
	op_swap(*stack_b);
}

/*	op_ss()
*	calls op_swap() on both stacks and prints ss on stdout
*/
void	op_ss(t_stack **stack_a, t_stack **stack_b)
{
	op_swap(*stack_a);
	op_swap(*stack_b);
}
