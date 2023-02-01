/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:37:01 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/01 18:54:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	stack_new()
*	create a new node for a stack
*	returns the node if everything went smoothly, NULL if something went wrong
*/
t_stack	*stack_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/*	stack_get_tail()
*	finds the tail of the stack
*	returns a pointer to the tail
*/
t_stack	*stack_get_tail(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*	stack_add_back()
*	create a new node for the given stack and add it to the back/bottom of the stack
*/
void	stack_add_back(t_stack *node, t_stack **stack)
{
	t_stack	*tail;

	if (node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	tail = stack_get_tail(*stack);
	tail->next = node;
}

/* stack_get_size()
*	returns the number of nodes on a stack
*/
int		stack_get_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
