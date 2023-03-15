/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/15 17:22:51 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	main()
*	validate that the given input is correct
*	build stack a of the given input
*	check if the stack is already sorted
*	sort the stack if necessary
*	print the steps to sort the stack
*	free stacks a and b
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**input;

	if (argc < 2)
		return (0);
	input = input_validate(argv, argc);
	if (input == NULL)
	{
		free(input);
		return (0);
	}
	stack_a = stack_build(input);
	free_input(input);
	stack_b = NULL;
	stack_size = stack_get_size(stack_a);
	stack_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
