/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:39:41 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 20:30:14 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*	op_rotate()
*	shift up all nodes of given stack by one
*/
static void	op_rotate(t_stack **stack)
{
	t_stack	*tail;

	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = *stack;
	*stack = (*stack)->next;
	tail->next->next = NULL;
}

/*	op_ra()
*	shift up all nodes of stack_a by one
*	the first element becomes the last one
*	print ra on stdout
*/
int	op_ra(t_stack **stack_a)
{
	if (!*stack_a)
		return (0);
	op_rotate(stack_a);
	return (1);
}

/*	op_rb()
*	shift up all nodes of stack_b by one
*	the first element becomes the last one
*	print rb on stdout
*/
int	op_rb(t_stack **stack_b)
{
	if (!*stack_b)
		return (0);
	op_rotate(stack_b);
	return (1);
}

/*	op_rr()
*	shift up all nodes of stack_a and stack_b by one
*	the first element becomes the last one
*	print rr on stdout
*/
int	op_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		return (0);
	op_rotate(stack_a);
	op_rotate(stack_b);
	return (1);
}
