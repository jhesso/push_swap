/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:45:32 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/14 18:57:53 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	op_push
*	Pushes the top element of source stack to destination stack
*/
static void	op_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*	op_pa()
*	Take the first element at the top of b and put it at the top of a.
*	Do nothing if b is empty.
*	print "pa" on stdout
*/
void	op_pa(t_stack **stack_a, t_stack **stack_b)
{
	op_push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/*	op_pb()
*	Take the first element at the top of a and put it at the top of b.
*	Do nothing if a is empty.
*	print "pb" on stdout
*/
void	op_pb(t_stack **stack_b, t_stack **stack_a)
{
	op_push(stack_a, stack_b);
	ft_putstr("pb\n");
}
