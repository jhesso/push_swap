/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:31:17 by jhesso            #+#    #+#             */
/*   Updated: 2023/03/30 04:13:10 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	do_op(t_stack *a, t_stack *b, char *operation)
{
	if (!ft_strcmp(operation, "sa\n"))
		op_sa(&a);
	else if (!ft_strcmp(operation, "sb\n"))
		op_sb(&b);
	else if (!ft_strcmp(operation, "ss\n"))
		op_ss(&a, &b);
	else if (!ft_strcmp(operation, "pa\n"))
		op_pa(&a, &b);
	else if (!ft_strcmp(operation, "pb\n"))
		op_pb(&b, &a);
	else if (!ft_strcmp(operation, "ra\n"))
		op_ra(&a);
	else if (!ft_strcmp(operation, "rb\n"))
		op_rb(&b);
	else if (!ft_strcmp(operation, "rr\n"))
		op_rr(&a, &b);
	else if (!ft_strcmp(operation, "rra\n"))
		op_rra(&a);
	else if (!ft_strcmp(operation, "rrb\n"))
		op_rrb(&b);
	else if (!ft_strcmp(operation, "rrr\n"))
		op_rrr(&a, &b);
}

static void	do_operations(t_stack *a, t_stack *b, char **operations)
{
	int	i;

	i = 0;
	while (operations[i])
	{
		do_op(a, b, operations[i]);
		i++;
	}
}

/*	checker()
*	runs the given operations on stacks a and b
*	checks if stack a is sorted in the end
*	prints OK or KO depending if sorted or not
*/
void	checker(t_stack *a, t_stack *b, char **operations)
{
	do_operations(a, b, operations);
	if (!stack_is_sorted(a))
		ft_printf("KO\n");
	else
		if (!b)
			ft_printf("OK\n");
}
