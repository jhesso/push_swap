/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:39:41 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/17 17:34:55 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	op_rotate()
*	shift up all nodes of given stack by one
*/
static void	op_rotate(t_stack **stack)
{
	while (stack)
	{
		op_swap(stack);
		stack = stack->next;
	}
}

/*	op_ra()
*	shift up all nodes of stack_a by one
*	the first element becomes the last one
*	print ra on stdout
*/
void	op_ra(t_stack **stack_a)
{
	op_rotate(stack_a);
	ft_printf("ra\n");
}

/*	op_rb()
*	shift up all nodes of stack_b by one
*	the first element becomes the last one
*	print rb on stdout
*/
void	op_rb(t_stack **stack_b)
{
	op_rotate(stack_b);
	ft_printf("rb\n");
}

/*	op_rr()
*	shift up all nodes of stack_a and stack_b by one
*	the first element becomes the last one
*	print rr on stdout
*/
void	op_rr(t_stack **stack_a, t_stack **stack_b)
{
	op_rotate(stack_a);
	op_rotate(stack_b);
	ft_printf("rr\n");
}
