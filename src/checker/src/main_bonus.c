/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:01:45 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 03:22:17 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	char	**operations;
	t_stack	*a;
	t_stack	*b;
	char	**input;

	if (ac < 2)
		return (0);
	input = input_validate(av, ac);
	if (!input)
	{
		free(input);
		return (0);
	}
	a = stack_build(input);
	free_input(input);
	b = NULL;
	stack_index(a, stack_get_size(a));
	operations = get_operations();
	operations_validate(operations);
	checker(a, b, operations);
	return (0);
}
