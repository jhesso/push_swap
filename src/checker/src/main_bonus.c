/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:33:18 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 20:49:34 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	check_if_sorted(t_stack *a, t_stack *b)
{
	if (b)
		ft_printf("KO\n");
	else if (!stack_is_sorted(a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int ac, char **av)
{
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
	execute_op(&a, &b);
	check_if_sorted(a, b);
	return (0);
}
