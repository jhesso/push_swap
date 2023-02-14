/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:49:01 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/14 14:08:35 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	op_swap(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}
