/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:05:16 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/11 15:48:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

static void	operations_free(t_operations **operations)
{
	t_operations	*tmp;

	if (!operations || !(*operations))
		return ;
	while (*operations)
	{
		tmp = (*operations)->next;
		free(*operations);
		*operations = tmp;
	}
	*operations = NULL;
}

void	checker_error_print(t_stack **a, t_stack **b, t_operations **operations)
{
	operations_free(operations);
	error_print(a, b);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	char			**input;
	t_operations	*operations;

	if (argc < 2)
		return (0);
	operations = read_operations();
	ft_printf("read operations:\n");
	while (operations)
	{
		ft_printf("%s", operations->operation);
		operations = operations->next;
	}
	return (0);
	input = input_validate(argv, argc);
	a = stack_build(input);
	free_input(input);
	b = NULL;
	// run_operations(operations);
	if (!stack_is_sorted(a) || b != NULL)
	{
		ft_printf("KO\n");
		stack_free(&a);
		stack_free(&b);
		return (0);
	}
	ft_printf("OK\n");
	stack_free(&a);
	stack_free(&b);
	return (0);
}
