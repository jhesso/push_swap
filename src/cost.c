/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:31:25 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/28 16:32:57 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	get_cost()
*	calculates the cost of moving each element of stack b into the correct
*	position in stack a
*/
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *a;
	temp_b = *b;
	size_a = stack_get_size(temp_a);
	size_b = stack_get_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

/*	do_cheapest_move()
*	Finds the element in stack b with the cheapest 'cost' to move to stack a
*	and moves it to the correct position in stack a
*/
void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (ft_absolute(temp->cost_a) + ft_absolute(temp->cost_b) < cheapest)
		{
			cheapest = ft_absolute(temp->cost_a) + ft_absolute(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	move(a, b, cost_a, cost_b);
}
