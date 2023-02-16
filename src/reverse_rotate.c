/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:46:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/16 11:52:04 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	op_reverse_rotate()
*	shift down all nodes of given stack by one.
*	the last node becomes the first one
*/
static void	op_reverse_rotate(t_stack *stack)
{

}

/*	op_rra()
*	shift down all nodes of stack_a by one.
*	the last node becomes the first one
*	print rra on stdout
*/
void	op_rra(t_stack *stack_a)
{
	op_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

/*	op_rrb()
*	shift down all nodes of stack_b by one.
*	the last node becomes the first one
*	print rrb on stdout
*/
void	op_rrb(t_stack *stack_b)
{
	op_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

/*	op_rrr
*	shift down all nodes of both stacks by one
*	the last node becomes the first one
*	print rrr on stdout
*/
void	op_rrr(t_stack *stack_a, t_stack *stack_b)
{
	op_reverse_rotate(stack_a);
	op_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
