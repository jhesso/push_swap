/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:39:50 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/02 17:54:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	debug_stack_print_values(t_stack *stack)
{
	int	nb;

	nb = 0;
	while (stack != NULL)
	{
		ft_printf("node: %d value: %d index: %d\n", nb, stack->value, stack->index);
		stack = stack->next;
		nb++;
	}
}
