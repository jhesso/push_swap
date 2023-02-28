/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:40:56 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/28 19:54:07 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	error_print()
*	frees stacks a and b, prints Error\n on stderr and exits with code 1
*/
void	error_print(t_stack **stack_a, t_stack **stack_b)
{
	// if leaks, this might work
	if (stack_a == NULL || stack_a != NULL)
		stack_free(stack_a);
	if (stack_b == NULL || stack_b != NULL)
		stack_free(stack_b);
	// stack_free(stack_a);
	// stack_free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
