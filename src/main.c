/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/02/01 19:11:56 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Start:
		We have 2 stacks a and b. when the program is launched, stack a is given as a parameter.
		b is empty at the beginning.

	Goal:
		Sort the given stack (or list) a in ascending order.
		The program must display the smallest list of instructions possible to sort the stack
		a, the smallest number being at the top.

	Operations:
		- sa (swap a): Swap the first 2 elements at the top of stack a.
			Do nothing if there is only one or no elements.
		- sb (swap b): Swap the first 2 elements at the top of stack b.
			Do nothing if there is only one or no elements.
		- ss: sa and sb at the same time.
		- pa (push a): Take the first element at the top of b and put it at the top of a.
			Do nothing if b is empty.
		- pb (push b): Take the first element at the top of a and put it at the top of b.
			Do nothing if a is empty.
		- ra (rotate a): Shift up all elements of stack a by 1.
			The first element becomes the last one.
		- rb (rotate b): Shift up all elements of stack b by 1.
			The first element becomes the last one.
		- rr : ra and rb at the same time.
		- rra (reverse rotate a): Shift down all elements of stack a by 1.
			The last element becomes the first one.
		- rrb (reverse rotate b): Shift down all elements of stack b by 1.
			The last element becomes the first one.
		- rrr : rra and rrb at the same time.

	Error cases:
		In case of error, the program displays "Error" followed by a \n on the standard error.
		Example error cases: some arguments aren't integers, some arguments are bigger than an integer
		and/or there are duplicates.
*/

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
		// ! print invalid input error
	stack_a = stack_build(argv);
	stack_b = NULL;
	stack_size = stack_get_size(stack_a);
	if (stack_size != argc - 1) ;
		// ! print error building stack
	stack_index(stack_a, stack_size);
	// is_sorted() return 1 if sorted, 0 if not
	// get stack size() return uint stack size
	// solve roblem()
	// print solution()
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
