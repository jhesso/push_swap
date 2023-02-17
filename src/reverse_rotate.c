/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:46:23 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/17 15:59:57 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	op_shift_down()
*	shift down the first node on the given stack
!	pretty sure this is not what I actually want now that I think of it cause this
!	swaps the values but I just want to move the values down by one. hmmm...
*/
// static void	op_shift_down(t_stack *stack)
// {
// 	int	temp;

// 	if (!stack || stack->next == NULL)
// 		return ;
// 	temp = stack->next->value;
// 	stack->next->value = stack->value;
// 	stack->value = temp;
// 	temp = stack->next->index;
// 	stack->next->index = stack->index;
// 	stack->index = temp;
// }

/*	op_reverse_rotate()
*	shift down all nodes of given stack by one.
*	the last node becomes the first one
*/
// static void	op_reverse_rotate(t_stack *stack)
// {
// 	// get the second to last element, that becomes the last one (next=NULL)
// 	// last becomes head
// 	// head becomes second
// 	// ...
// 	// profit!
// 	t_stack	*old_head; // keeping track of head (old head)
// 	t_stack	*old_tail; // keeping track of tail (old tail)

// 	old_head = stack;
// 	old_tail = stack_get_tail(stack);
// 	while (stack->next->next != NULL)
// 		stack = stack->next;
// 	stack->next = NULL;
// 	old_tail->next = old_head;
// }

/*	op_reverse_rotate()
*	shift down all nodes of given stack by one.
*	the last node becomes the first one
*/
static void	op_reverse_rotate(t_stack *stack)
{
	t_stack	*old_tail;
	int		old_head_value;
	int		old_head_index;
	int		old_tail_value;
	int		old_tail_index;
	int		temp_value;
	int		temp_index;

	old_tail = stack_get_tail(stack);
	old_head_value = stack->value;
	old_head_index = stack->index;
	old_tail_value = old_tail->value;
	old_tail_index = old_tail->index;
	while (stack)
	{
		temp_value = stack->next->value;
		temp_index = stack->next->index;
		stack->next->value = stack->value;
		stack->next->index = stack->index;
	}
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
