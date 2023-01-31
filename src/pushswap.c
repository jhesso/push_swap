/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:06:38 by jhesso            #+#    #+#             */
/*   Updated: 2023/01/27 12:01:43 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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

int	main(int argc. char **argv)
{
	if (argc < 2) // incase no parameter is given, dont display anything and give the prompt back.
		return (0);
	validate_input(argv); // return 1 if valid, 0 if not
	// build stack a() return stack a
	// is_sorted() return 1 if sorted, 0 if not
	// get stack size() return uint stack size
	// solve roblem()
	// print solution()
	// free stacks()
	return (0);
}
