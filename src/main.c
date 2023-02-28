/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/28 17:02:33 by jhesso           ###   ########.fr       */
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
*
*	01 02 03... are treated as 1 2 3...
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!input_validate(argv, argc))
		error_print(NULL, NULL);
	ft_printf("building stack...\n");
	stack_a = stack_build(argv); //! so stack building is now broken.. nice :D
	ft_printf("do we even get this far\n");
	stack_b = NULL;
	stack_size = stack_get_size(stack_a);
	if (stack_size != argc - 1)
		error_print(&stack_a, &stack_b);
	stack_index(stack_a, stack_size);
	if (stack_is_sorted(stack_a))
	{
		stack_free(&stack_a);
		return (0);
	}
	ft_printf("do we even get this far\n");
	push_swap(&stack_a, &stack_b, stack_size);
	debug_stack_print_values(stack_a); //* print the stack a to make sure it is actually sorted
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
