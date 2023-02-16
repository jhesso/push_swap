/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:39:41 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/16 10:45:04 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	op_rotate()
*	shift up all nodes of given stack by one
*/
static void	op_rotate(t_stack *stack)
{

}

/*	op_ra()
*	shift up all nodes of stack_a by one
*/
void	op_ra(t_stack *stack_a)
{
	op_rotate(stack_a);
	ft_printf("ra\n");
}

/*	op_rb()
*	shift up all nodes of stack_b by one
*/
void	op_rb(t_stack *stack_b)
{
	op_rotate(stack_b);
	ft_printf("rb\n");
}
