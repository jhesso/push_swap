/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:34:44 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/28 16:54:35 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	rev_rotate_both()
*	Reverse rotates both stacks until one of them is in position.
*/
static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		op_rrr(a, b);
	}
}

/*	rotate_both()
*	rotates both stacks until one of them is in position
*/
static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		op_rr(a, b);
	}
}

/*	rotate_a()
*	rotate stack a until it is in position
*	if cost is negative, the stack will be reverse rotated
*/
static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			op_rra(a);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			op_ra(a);
			(*cost)--;
		}
	}
}

/*	rotate_b()
*	rotate stack b until it is in position
*	if cost is negative, the stack will be reverse rotated
*/
static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			op_rrb(b);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			op_rb(b);
			(*cost)--;
		}
	}
}

/*	move()
*	chooses which move to make to get the b stack element
*	to the correct position in stack a
*/
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	op_pa(a, b);
}
